#include <irrlicht.h>


int main(void)
{
    //Device, driver et graphe de scene.
    irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(800,800),32,false,false,false);
    irr::video::IVideoDriver* driver = device->getVideoDriver ();
    irr::scene::ISceneManager *sceneManager = device->getSceneManager ();

     //On rend invisible le curseur.
    device->getCursorControl ()-> setVisible (false);

    //La camera
    irr::SKeyMap keyMap[5];
    keyMap[0].Action = irr::EKA_MOVE_FORWARD;
    keyMap[0].KeyCode = irr::KEY_KEY_Z;
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
    keyMap[1].KeyCode = irr::KEY_KEY_S;
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;
    keyMap[2].KeyCode = irr::KEY_KEY_Q;
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
    keyMap[3].KeyCode = irr::KEY_KEY_D;
    keyMap[4].Action = irr::EKA_JUMP_UP;
    keyMap[4].KeyCode = irr::KEY_SPACE;
    irr::scene::ICameraSceneNode *camera;
    camera = sceneManager->addCameraSceneNodeFPS (0,100.0f,0.02f, -1, keyMap, 5, false, 0.4);
    camera->setPosition(irr::core::vector3df(0.0f, 0.0f, 0.0f));

    //La chaine pour le titre de la fenetre
    irr::core::vector3df posCam;
    wchar_t titre[100];


camera->setPosition(irr::core::vector3df(60.0f, 60.0f, 0.0f));
camera->setTarget(irr::core::vector3df(0.0f, 40.0f, 0.0f));

irr::scene::IParticleSystemSceneNode* particleSystem =
    sceneManager->addParticleSystemSceneNode(false);

irr::scene::IParticleEmitter* emitter = particleSystem->createBoxEmitter(
    irr::core::aabbox3d<irr::f32>(-6,0,-6,6,1,6), // coordonnees de la boite
    irr::core::vector3df(0.0f,0.06f,0.0f),        // direction de diffusion
    80,100,                                       // nb particules emises a la sec min / max
    irr::video::SColor(0,255,255,255),            // couleur la plus sombre
    irr::video::SColor(0,255,255,255),            // couleur la plus claire
    600, 1200,                                    // duree de vie min / max
    0,                                            // angle max d'ecart / direction prevue
    irr::core::dimension2df(8.0f,8.0f),           // taille minimum
    irr::core::dimension2df(14.0f,14.0f));        // taille maximum

particleSystem->setEmitter(emitter);              // on attache l'emetteur
emitter->drop();                                  // plus besoin de ca

particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);          // insensible a la lumiere
particleSystem->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);     // desactive zbuffer pour surfaces derriere
particleSystem->setMaterialTexture(0, driver->getTexture("media/fire.bmp"));     // on colle une texture
particleSystem->setMaterialType(irr::video::EMT_TRANSPARENT_VERTEX_ALPHA); // application transparence


    //La boucle de rendu
    while (device->run())
    {
        posCam = camera->getPosition();
        swprintf(titre, 100, L"FPS : %d (mode debug) |  PosCam :  "
        "X : %f Y : %f Z : %f", driver->getFPS(), posCam.X, posCam.Y, posCam.Z);
        device->setWindowCaption(titre);
        //On utilise un fond blanc pour voir les particules
        driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        sceneManager->drawAll ();
        driver->endScene ();
    }

    device->drop();
    return 0;
}
