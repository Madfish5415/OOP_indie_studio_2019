** EPITECH PROJECT, 2020
** BootstrapIndie
** File description:
** main
*/

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

enum
{
    // I use this ISceneNode ID to indicate a scene node that is
    // not pickable by getSceneNodeAndCollisionPointFromRay()
    ID_IsNotPickable = 0,

    // I use this flag in ISceneNode IDs to indicate that the
    // scene node can be picked by ray selection.
    IDFlag_IsPickable = 1 << 0,

    // I use this flag in ISceneNode IDs to indicate that the
    // scene node can be highlighted.  In this example, the
    // homonids can be highlighted, but the level mesh can't.
    IDFlag_IsHighlightable = 1 << 1
};

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

bool collision(scene::ISceneNode* one, scene::ISceneNode* two) {
   core::aabbox3d<f32> b1, b2;

   b1 = one->getBoundingBox ();
   b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   two->getRelativeTransformation().transformBoxEx( b2 );
   return (b1.intersectsWithBox( b2 ));
}

int main ()
{
    // create device
    MyEventReceiver receiver;

    IrrlichtDevice* device = createDevice(video::EDT_OPENGL,
            core::dimension2d<u32>(1280, 720), 16, false, false, false, &receiver);

    if (device == 0)
        return 1; // could not create selected driver.

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();

    device->getFileSystem()->addFileArchive("./media/map-20kdm2.pk3");

    scene::IAnimatedMesh* q3levelmesh = smgr->getMesh("20kdm2.bsp");
    scene::IMeshSceneNode* q3node = 0;

    // The Quake mesh is pickable, but doesn't get highlighted.
    if (q3levelmesh)
        q3node = smgr->addOctreeSceneNode(q3levelmesh->getMesh(0), 0);

        scene::ITriangleSelector* map_selector = 0;

    if (q3node)
    {
        q3node->setPosition(core::vector3df(-1350,-130,-1400));
        map_selector = smgr->createOctreeTriangleSelector(
                q3node->getMesh(), q3node, 128);
        q3node->setTriangleSelector(map_selector);
        // We're not done with this selector yet, so don't drop it.
    }

    scene::IAnimatedMeshSceneNode* node =
        smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/ninja.b3d"));

    if (node)
    {
        node->setMaterialFlag(video::EMF_LIGHTING, false);

        node->setFrameLoop(183, 204);
        node->setAnimationSpeed(15);
//      node->setMD2Animation(scene::EMAT_RUN);

        node->setScale(core::vector3df(10));
        node->setPosition(core::vector3df(-75,-120,-80));
        node->setRotation(core::vector3df(0,-90,0));
//      node->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));
    }

    scene::IAnimatedMeshSceneNode* fairy = 0;
    video::SMaterial material;

    fairy = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/faerie.md2"),
                        0, IDFlag_IsPickable | IDFlag_IsHighlightable);
    fairy->setPosition(core::vector3df(-90,-15,-140)); // Put its feet on the floor.
    fairy->setScale(core::vector3df(1.6f)); // Make it appear realistically scaled
    fairy->setMD2Animation(scene::EMAT_POINT);
    fairy->setAnimationSpeed(20.f);
    material.setTexture(0, driver->getTexture("./media/faerie2.bmp"));
    material.Lighting = true;
    material.NormalizeNormals = true;
    fairy->getMaterial(0) = material;

    scene::ITriangleSelector* fairy_selector = 0;

     if (fairy)
    {
        fairy_selector = smgr->createOctreeTriangleSelector(
                fairy->getMesh(), fairy, 128);
        fairy->setTriangleSelector(fairy_selector);
        // We're not done with this selector yet, so don't drop it.
    }

    if (fairy_selector)
    {
        scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
            fairy_selector, node, core::vector3df(30,50,30),
            core::vector3df(0,-10,0), core::vector3df(0,30,0));
        fairy_selector->drop(); // As soon as we're done with the selector, drop it.
        node->addAnimator(anim);
        anim->drop();  // And likewise, drop the animator when we're done referring to it.
    }

    scene::ISceneNode* cube = smgr->addCubeSceneNode();

    if (cube)
    {
        cube->setMaterialTexture(0, driver->getTexture("../../media/t351sml.jpg"));
        cube->setMaterialFlag(video::EMF_LIGHTING, false);
    }
    if (map_selector)
    {
        const core::aabbox3d<f32>& box = node->getBoundingBox();
        core::vector3df radius = box.MaxEdge - box.getCenter();
        scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
            map_selector, node, radius,
            core::vector3df(0,-10,0), core::vector3df(0,0,0));
        node->addAnimator(anim);
        const core::aabbox3d<f32>& cube_box = cube->getBoundingBox();
        radius = cube_box.MaxEdge - cube_box.getCenter();
        anim = smgr->createCollisionResponseAnimator(
            map_selector, cube, radius,
            core::vector3df(0,-10,0), core::vector3df(0,0,0));
        cube->addAnimator(anim);
        anim->drop();  // And likewise, drop the animator when we're done referring to it.
    }

    smgr->addCameraSceneNodeFPS();
    device->getCursorControl()->setVisible(false);

    int lastFPS = -1;

    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    u32 then = device->getTimer()->getTime();

    // This is the movemen speed in units per second.
    const f32 MOVEMENT_SPEED = 100.f;

     scene::ILightSceneNode * light = smgr->addLightSceneNode(0, core::vector3df(-60,100,400),
        video::SColorf(1.0f,1.0f,1.0f,1.0f), 600.0f);
    light->setID(ID_IsNotPickable);

    while(device->run())
    {
        // Work out a frame delta time.
        const u32 now = device->getTimer()->getTime();
        const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
        then = now;
        bool cur_mov = false;
        bool sneak = false;

        core::vector3df nodePosition = node->getPosition();

        if(receiver.IsKeyDown(irr::KEY_KEY_D)) {
            nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
            node->setRotation(core::vector3df(0, 0, 0));
            cur_mov = true;
        }
        else if(receiver.IsKeyDown(irr::KEY_KEY_Q)) {
            nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
            node->setRotation(core::vector3df(0, 180, 0));
            cur_mov = true;
        }

        if(receiver.IsKeyDown(irr::KEY_KEY_Z)) {
            nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
            node->setRotation(core::vector3df(0, -90, 0));
            cur_mov = true;
        }
        else if(receiver.IsKeyDown(irr::KEY_KEY_S)) {
            nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
            node->setRotation(core::vector3df(0, 90, 0));
            cur_mov = true;
        }

        if(receiver.IsKeyDown(irr::KEY_KEY_W)) {
            sneak = true;
        }
        node->setPosition(nodePosition);


        if (cur_mov && node->getFrameNr() >= 183) {
            node->setFrameLoop(0, 13);
            node->setCurrentFrame(0);
        }
        if (cur_mov && !sneak && node->getFrameNr() > 13 && node->getFrameNr() <= 30) {
            node->setFrameLoop(0, 13);
            node->setCurrentFrame(node->getFrameNr() - 14);
        }
        if (sneak) {
            if (node->getFrameNr() < 14) {
                node->setFrameLoop(14, 29);
                node->setCurrentFrame(node->getFrameNr() + 14);
            }
        }
        if (!cur_mov && node->getFrameNr() < 183) {
            node->setFrameLoop(183, 204);
        }

        if (collision(node, cube) && (node->getFrameNr() >= 182 || node->getFrameNr() < 174)) {
            node->setFrameLoop(174, 182);
        }

         smgr->getActiveCamera()->setPosition(core::vector3df(nodePosition.X + 50, nodePosition.Y + 150, nodePosition.Z));
         smgr->getActiveCamera()->setTarget(core::vector3df(nodePosition.X, nodePosition.Y + 20, nodePosition.Z));

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