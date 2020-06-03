# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

project(IndieStudio)

set (CMAKE_CXX_STANDARD 17)

# Permet de placer l'executable a la racine du projt apres la compilation
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

# Créer un chemin relatif
# include_directories(${CMAKE_SOURCE_DIR}/src)

# Crée des variables avec les fichiers à compiler
set(SRCS
        src/main.cpp
        src/ecs/component/Player.cpp
        src/ecs/component/Position.cpp
        src/ecs/component/Render.cpp
        src/ecs/component/Velocity.cpp
        src/ecs/event/Input.cpp
        src/ecs/system/Motion.cpp
        src/ecs/system/Player.cpp
        src/ecs/system/Render.cpp
        src/GameLoop.cpp
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
        src/ecs/component/Player.hpp
        src/ecs/component/Position.hpp
        src/ecs/component/Render.hpp
        src/ecs/component/Velocity.hpp
        src/ecs/event/Input.hpp
        src/ecs/system/Motion.hpp
        src/ecs/system/Player.hpp
        src/ecs/system/Render.hpp
        src/GameLoop.hpp
        )


# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(bomberman ${SRCS} ${HEADERS})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package(Irrlicht)

find_package(SFML)

if (Irrlicht_FOUND AND SFML_FOUND)
    # Une fois la dépendance trouvée, nous l'incluons au projet
    target_include_directories(bomberman PUBLIC ${Irrlicht_INCLUDE_DIRS} ${SFML_INCLUDE_DIRS})
    message(SUCCESS_MESSAGE: " This is the irrlicht include path ${Irrlicht_INCLUDE_DIRS}\n And this is the sfml include path ${SFML_INCLUDE_DIRS}")
    target_link_libraries(bomberman ${Irrlicht_LIBRARIES} ${SFML_LIBRARIES})
    message(SUCCESS_MESSAGE: " This is the irrlicht lib path ${Irrlicht_LIBRARIES}\n And this is the sfml libraries path ${SFML_LIBRARIES}")
else ()
    if (NOT Irrlicht_FOUND)
        # Sinon, nous affichons un message
        message(FATAL_ERROR "libIrrlicht not found")
    else ()
        message(FATAL_ERROR "libSFML not found")
    endif ()
endif ()