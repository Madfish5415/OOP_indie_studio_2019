# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté hello
project(helloIRR)

# Créer un chemin relatif
# include_directories(${CMAKE_SOURCE_DIR}/src)

# Crée des variables avec les fichiers à compiler
set(SRCS
        src/main.cpp
        src/ecs/component/AI.cpp
        src/ecs/component/Animation.cpp
        src/ecs/component/BombStats.cpp
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
    )

set(HEADERS
        src/ecs/AEvent.hpp
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
        )


# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(main ${SRCS} ${HEADERS})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package (Irrlicht)

find_package (SFML)

if (Irrlicht_FOUND AND SFML_FOUND)
    # Une fois la dépendance trouvée, nous l'incluons au projet
    target_include_directories(main PUBLIC ${Irrlicht_INCLUDE_DIRS} ${SFML_INCLUDE_DIRS})
    message(SUCCESS_MESSAGE: " This is the include path ${Irrlicht_INCLUDE_DIRS}\n")
    target_link_libraries (main ${Irrlicht_LIBRARIES} ${SFML_LIBRARIES})
else ()
    # Sinon, nous affichons un message
    message(FATAL_ERROR "libIrrlicht not found")
endif ()