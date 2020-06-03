/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include <irrlicht.h>

using namespace irr;

class MyEventReceiver : public IEventReceiver
{
public:
    // This is the one method that we have to implement
    virtual bool OnEvent(const SEvent& event)
    {
        // Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

        return false;
    }

    // This is used to check whether a key is being held down
    virtual bool IsKeyDown(EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }
    
    MyEventReceiver()
    {
        for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }

private:
    // We use this array to store the current state of each key
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

int main ()
{
    // create device
    MyEventReceiver receiver;

    IrrlichtDevice* device = createDevice(video::EDT_OPENGL,
            core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);

    if (device == 0)
        return 1; // could not create selected driver.

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();


    scene::ISceneNode *plan_node = smgr->addMeshSceneNode(smgr->getGeometryCreator()->createPlaneMesh(irr::core::dimension2d<irr::f32>(13, 13), irr::core::dimension2d<irr::u32>(10, 10)));
    if (plan_node) {
        plan_node->setMaterialTexture(0, driver->getTexture("./media/orange.png"));
        plan_node->setMaterialFlag(video::EMF_LIGHTING, false);
    }

    scene::ISceneNode * node = smgr->addSphereSceneNode();
    if (node)
    {
        node->setPosition(core::vector3df(0,0,30));
        node->setMaterialTexture(0, driver->getTexture("./media/wall.bmp"));
        node->setMaterialFlag(video::EMF_LIGHTING, false);
    }

    scene::ISceneNode* n = smgr->addCubeSceneNode();

    if (n)
    {
        n->setMaterialTexture(0, driver->getTexture("./media/t351sml.jpg"));
        n->setMaterialFlag(video::EMF_LIGHTING, false);
        scene::ISceneNodeAnimator* anim =
            smgr->createFlyCircleAnimator(core::vector3df(0,0,30), 20.0f);
        if (anim)
        {
            n->addAnimator(anim);
            anim->drop();
        }
    }

    scene::IAnimatedMeshSceneNode* anms =
        smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/ninja.b3d"));

    if (anms)
    {
        scene::ISceneNodeAnimator* anim =
            smgr->createFlyStraightAnimator(core::vector3df(100,0,60),
            core::vector3df(-100,0,60), 3500, true);
        if (anim)
        {
            anms->addAnimator(anim);
            anim->drop();
        }

        anms->setMaterialFlag(video::EMF_LIGHTING, false);

        anms->setFrameLoop(0, 13);
        anms->setAnimationSpeed(15);
//      anms->setMD2Animation(scene::EMAT_RUN);

        anms->setScale(core::vector3df(2.f,2.f,2.f));
        anms->setRotation(core::vector3df(0,-90,0));
//      anms->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));
    }

    smgr->addCameraSceneNodeFPS();
    device->getCursorControl()->setVisible(false);

    device->getGUIEnvironment()->addImage(
        driver->getTexture("./media/irrlichtlogoalpha2.tga"),
        core::position2d<s32>(10,20));

    gui::IGUIStaticText* diagnostics = device->getGUIEnvironment()->addStaticText(
        L"", core::rect<s32>(10, 10, 400, 20));
    diagnostics->setOverrideColor(video::SColor(255, 255, 255, 0));

    scene::IParticleSystemSceneNode* particleSystem = smgr->addParticleSystemSceneNode(false);

    scene::IParticleEmitter* emitter = particleSystem->createBoxEmitter(
    core::aabbox3df(-12,0,-6,6,1,6), // coordonnees de la boite
    core::vector3df(0.0f,0.06f,0.0f),        // direction de diffusion
    80,100,                                       // nb particules emises a la sec min / max
    video::SColor(0,255,255,255),            // couleur la plus sombre
    video::SColor(0,255,255,255),            // couleur la plus claire
    400, 600,                                    // duree de vie min / max
    0,                                            // angle max d'ecart / direction prevue
    core::dimension2df(8.0f,8.0f),           // taille minimum
    core::dimension2df(14.0f,14.0f));        // taille maximum

    particleSystem->setEmitter(emitter);              // on attache l'emetteur
    emitter->drop();                                  // plus besoin de ca

    particleSystem->setMaterialFlag(video::EMF_LIGHTING, false);          // insensible a la lumiere
    particleSystem->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);     // desactive zbuffer pour surfaces derriere
    particleSystem->setMaterialTexture(0, driver->getTexture("media/fire.bmp"));     // on colle une texture
    // particleSystem->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA); // application transparence

    int lastFPS = -1;

    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    u32 then = device->getTimer()->getTime();

    // This is the movemen speed in units per second.
    const f32 MOVEMENT_SPEED = 5.f;

    while(device->run())
    {
        // Work out a frame delta time.
        const u32 now = device->getTimer()->getTime();
        const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
        then = now;

        core::vector3df nodePosition = node->getPosition();

        if(receiver.IsKeyDown(irr::KEY_KEY_Z))
            nodePosition.Y += MOVEMENT_SPEED * frameDeltaTime;
        else if(receiver.IsKeyDown(irr::KEY_KEY_S))
            nodePosition.Y -= MOVEMENT_SPEED * frameDeltaTime;

        if(receiver.IsKeyDown(irr::KEY_KEY_Q))
            nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
        else if(receiver.IsKeyDown(irr::KEY_KEY_D))
            nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;

        node->setPosition(nodePosition);

        driver->beginScene(true, true, video::SColor(255,113,113,133));

        smgr->drawAll(); // draw the 3d scene
        device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

        driver->endScene();

        int fps = driver->getFPS();

        if (lastFPS != fps)
        {
            core::stringw tmp(L"Movement Example - Irrlicht Engine [");
            tmp += driver->getName();
            tmp += L"] fps: ";
            tmp += fps;

            device->setWindowCaption(tmp.c_str());
            lastFPS = fps;
        }
    }

    device->drop();
    
    return 0;
}