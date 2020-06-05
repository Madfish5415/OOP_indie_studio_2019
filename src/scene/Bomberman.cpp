/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** Bomberman.cpp
*/

#include "Bomberman.hpp"

#include "../ecs/Universe.hpp"
#include "../ecs/component/Render3d.hpp"
#include "../ecs/component/Transform.hpp"
#include "../ecs/system/Render.hpp"

void scene::Bomberman::init(ecs::WorldManager *worldManager)
{
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Render3d>();
    // worldManager->registerComponent<ecs::component::Transform>();

    worldManager->registerSystem<ecs::system::Render>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        worldManager->setSystemSignature<ecs::system::Render>(signature);
    }

    ecs::Entity ground = worldManager->createEntity();
    irr::scene::IMeshSceneNode *ground_mesh = smgr->addMeshSceneNode(smgr->getGeometryCreator()->createPlaneMesh(irr::core::dimension2df(10, 10), irr::core::dimension2du(13, 13)));

    if (ground_mesh) {
        ground_mesh->setMaterialTexture(0, driver->getTexture("./media/not_a_petite_fille.png"));
        ground_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    worldManager->addComponent<ecs::component::Render3d>(ground, ecs::component::Render3d(ground_mesh));

    ecs::Entity camera = worldManager->createEntity();
    worldManager->addComponent<ecs::component::Render3d>(camera, ecs::component::Render3d(smgr->addCameraSceneNodeFPS()));
}