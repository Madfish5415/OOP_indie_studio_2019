# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

project(IndieStudio)

set(CMAKE_CXX_STANDARD 17)

# Permet de placer l'executable a la racine du projt apres la compilation
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}) 

# Créer un chemin relatif
# include_directories(${CMAKE_SOURCE_DIR}/src)

# Crée des variables avec les fichiers à compiler
set(SRCS
        src/main.cpp
        src/ecs/component/AI.cpp
        src/ecs/component/Animation.cpp
        src/ecs/component/BombStats.cpp
        src/ecs/component/BombTimer.cpp
        src/ecs/component/Button.cpp
        src/ecs/component/HitboxDetection.cpp
        src/ecs/component/Image.cpp
        src/ecs/component/LookingView.cpp
        src/ecs/component/Lootable.cpp
        src/ecs/component/MessageBox.cpp
        src/ecs/component/Motion.cpp
        src/ecs/component/Music.cpp
        src/ecs/component/Owner.cpp
        src/ecs/component/Player.cpp
        src/ecs/component/Render3d.cpp
        src/ecs/component/Size.cpp
        src/ecs/component/Sound.cpp
        src/ecs/component/Stats.cpp
        src/ecs/component/Text.cpp
        src/ecs/component/Transform.cpp
        src/ecs/component/Unbreakable.cpp
        src/ecs/system/Image.cpp
        src/ecs/system/Music.cpp
        src/scene/Bomberman.cpp
        src/scene/Menu.cpp
        src/scene/PlayerSelector.cpp
        src/EventReceiver.cpp
        src/ecs/Universe.cpp
    )

set(HEADERS
        src/ecs/Event.hpp
        src/ecs/ComponentArray.hpp
        src/ecs/ComponentManager.hpp
        src/ecs/Def.hpp
        src/ecs/EntityManager.hpp
        src/ecs/EventManager.hpp
        src/ecs/IComponentArray.hpp
        src/ecs/System.hpp
        src/ecs/SystemManager.hpp
        src/ecs/WorldManager.hpp
        src/ecs/component/AI.hpp
        src/ecs/component/Animation.hpp
        src/ecs/component/BombStats.hpp
        src/ecs/component/BombTimer.hpp
        src/ecs/component/Button.hpp
        src/ecs/component/HitboxDetection.hpp
        src/ecs/component/Image.hpp
        src/ecs/component/LookingView.hpp
        src/ecs/component/Lootable.hpp
        src/ecs/component/MessageBox.hpp
        src/ecs/component/Motion.hpp
        src/ecs/component/Music.hpp
        src/ecs/component/Owner.hpp
        src/ecs/component/Player.hpp
        src/ecs/component/Render3d.hpp
        src/ecs/component/Size.hpp
        src/ecs/component/Sound.hpp
        src/ecs/component/Stats.hpp
        src/ecs/component/Text.hpp
        src/ecs/component/Transform.hpp
        src/ecs/component/Unbreakable.hpp
        src/ecs/system/Image.hpp
        src/ecs/system/Music.hpp
        src/scene/Bomberman.hpp
        src/scene/Menu.hpp
        src/scene/PlayerSelector.hpp
        src/EventReceiver.hpp
        src/ecs/Universe.hpp
        )


# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(bomberman ${SRCS} ${HEADERS})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package (Irrlicht)

find_package (SFML)

if (Irrlicht_FOUND AND SFML_FOUND)
    # Une fois la dépendance trouvée, nous l'incluons au projet
    target_include_directories(bomberman PUBLIC ${Irrlicht_INCLUDE_DIRS} ${SFML_INCLUDE_DIRS})
    message(SUCCESS_MESSAGE: " This is the irrlicht include path ${Irrlicht_INCLUDE_DIRS}\n And this is the sfml include path ${SFML_INCLUDE_DIRS}")
    target_link_libraries (bomberman ${Irrlicht_LIBRARIES} ${SFML_LIBRARIES})
    message(SUCCESS_MESSAGE: " This is the irrlicht lib path ${Irrlicht_LIBRARIES}\n And this is the sfml libraries path ${SFML_LIBRARIES}")
else ()
    if (NOT Irrlicht_FOUND)
        # Sinon, nous affichons un message
        message(FATAL_ERROR "libIrrlicht not found")
    else ()
        message(FATAL_ERROR "libSFML not found")
    endif ()
endif ()