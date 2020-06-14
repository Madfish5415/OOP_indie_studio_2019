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
        src/ecs/component/Collision.cpp
        src/ecs/component/Delay.cpp
        src/ecs/component/BombStats.cpp
        src/ecs/component/BombTimer.cpp
        src/ecs/component/Button.cpp
        src/ecs/component/Image.cpp
        src/ecs/component/Particle.cpp
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
        src/ecs/component/PushButton.cpp
        src/ecs/component/SkinColor.cpp
        src/ecs/component/Blink.cpp
        src/ecs/component/StatRender.cpp
        src/ecs/component/Timer.cpp
        src/ecs/component/TimerRender.cpp
        src/ecs/component/BoundingBox.cpp
        src/ecs/component/PlayerId.cpp
        src/ecs/component/PowerUp.cpp
        src/ecs/component/Breakable.cpp
        src/ecs/component/ToDelete.cpp
        src/ecs/component/Spinner.cpp
        src/ecs/component/Sliding.cpp
        src/ecs/component/PlayerIndex.cpp
        src/ecs/system/AI.cpp
        src/ecs/system/Music.cpp
        src/ecs/system/Movement.cpp
        src/ecs/system/Motion.cpp
        src/ecs/system/ExplosionDelay.cpp
        src/ecs/system/Sound.cpp
        src/ecs/system/Render.cpp
        src/ecs/system/Size.cpp
        src/ecs/system/Animation.cpp
        src/ecs/system/Button.cpp
        src/ecs/system/Blink.cpp
        src/ecs/system/Player.cpp
        src/ecs/system/StatRender.cpp
        src/ecs/system/Timer.cpp
        src/ecs/system/TimerRender.cpp
        src/ecs/system/BoundingBox.cpp
        src/ecs/system/BombTimer.cpp
        src/ecs/system/WinChecking.cpp
        src/ecs/system/PowerUp.cpp
        src/ecs/system/Spinner.cpp
        src/ecs/system/Shrink.cpp
        src/ecs/system/Sliding.cpp
        src/ecs/system/Countdown.cpp
        src/scene/Bomberman.cpp
        src/scene/Menu.cpp
        src/scene/LoadingMenu.cpp
        src/scene/WinScreen.cpp
        src/scene/PlayerSelector.cpp
        src/scene/Keybinding.cpp
        src/scene/GameHud.cpp
        src/scene/Pause.cpp
        src/scene/Settings.cpp
        src/scene/HowToPlay.cpp
        src/scene/CountDown.cpp
        src/EventReceiver.cpp
        src/core/Core.cpp
        src/ecs/Universe.cpp
        src/irrlicht/vector3df.cpp
        src/map-generator/MapGenerator.cpp
        src/ecs/event/Key.cpp
        src/ecs/event/TimerEnd.cpp
        src/irrlicht/GUIColorPicker.cpp
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
        src/ecs/component/Particle.hpp
        src/ecs/component/Collision.hpp
        src/ecs/component/BombStats.hpp
        src/ecs/component/BombTimer.hpp
        src/ecs/component/Button.hpp
        src/ecs/component/Delay.hpp
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
        src/ecs/component/SkinColor.hpp
        src/ecs/component/Stats.hpp
        src/ecs/component/Text.hpp
        src/ecs/component/Transform.hpp
        src/ecs/component/Unbreakable.hpp
        src/ecs/component/PushButton.hpp
        src/ecs/component/Blink.hpp
        src/ecs/component/StatRender.hpp
        src/ecs/component/Timer.hpp
        src/ecs/component/TimerRender.hpp
        src/ecs/component/BoundingBox.hpp
        src/ecs/component/PlayerId.hpp
        src/ecs/component/PowerUp.hpp
        src/ecs/component/Breakable.hpp
        src/ecs/component/ToDelete.hpp
        src/ecs/component/Spinner.hpp
        src/ecs/component/Sliding.hpp
        src/ecs/component/PlayerIndex.hpp
        src/ecs/system/Countdown.hpp
        src/ecs/system/Music.hpp
        src/ecs/system/WinChecking.hpp
        src/ecs/system/Movement.hpp
        src/ecs/system/Motion.hpp
        src/ecs/system/ExplosionDelay.hpp
        src/ecs/system/Sound.hpp
        src/ecs/system/Render.hpp
        src/ecs/system/Size.hpp
        src/ecs/system/Animation.hpp
        src/ecs/system/Button.hpp
        src/ecs/system/Blink.hpp
        src/ecs/system/Player.hpp
        src/ecs/system/StatRender.hpp
        src/ecs/system/Timer.hpp
        src/ecs/system/TimerRender.hpp
        src/ecs/system/BoundingBox.hpp
        src/ecs/system/BombTimer.hpp
        src/ecs/system/PowerUp.hpp
        src/ecs/system/Spinner.hpp
        src/ecs/system/Shrink.hpp
        src/ecs/system/Sliding.hpp
        src/ecs/system/AI.hpp
        src/scene/Bomberman.hpp
        src/scene/Menu.hpp
        src/scene/WinScreen.hpp
        src/scene/LoadingMenu.hpp
        src/scene/PlayerSelector.hpp
        src/scene/Keybinding.hpp
        src/scene/GameHud.hpp
        src/scene/Pause.hpp
        src/scene/Settings.hpp
        src/scene/HowToPlay.hpp
        src/scene/CountDown.hpp
        src/EventReceiver.hpp
        src/core/Core.hpp
        src/ecs/Universe.hpp
        src/map-generator/MapGenerator.hpp
        src/ecs/event/Key.hpp
        src/ecs/event/TimerEnd.hpp
        src/irrlicht/GUIColorPicker.hpp
        )

if (DEBUG)
    add_definitions(-DDEBUG)
endif()

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(bomberman ${SRCS} ${HEADERS})

add_custom_command(TARGET bomberman POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:bomberman> ../)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

set(Irrlicht_DIR libs/)
set(SFML_DIR libs/)

find_package (Irrlicht)


find_package (SFML)

if (Irrlicht_FOUND AND SFML_FOUND)
    # Une fois la dépendance trouvée, nous l'incluons au projet
    target_include_directories(bomberman PUBLIC ${Irrlicht_INCLUDE_DIRS} ${SFML_INCLUDE_DIRS})
    message(SUCCESS_MESSAGE: " This is the irrlicht include path ${Irrlicht_INCLUDE_DIRS}\n And this is the sfml include path ${SFML_INCLUDE_DIRS}")
    target_link_libraries (bomberman ${Irrlicht_LIBRARIES} ${SFML_AUDIO_LIBRARY} ${SFML_SYSTEM_LIBRARY})
    message(SUCCESS_MESSAGE: " This is the irrlicht lib path ${Irrlicht_LIBRARIES}\n And this is the sfml audio library path ${SFML_AUDIO_LIBRARY}\n And this is the sfml system library path ${SFML_SYSTEM_LIBRARY}")
else ()
    if (NOT Irrlicht_FOUND)
        # Sinon, nous affichons un message
        message(FATAL_ERROR "libIrrlicht not found")
    else ()
        message(FATAL_ERROR "libSFML not found")
    endif ()
endif ()