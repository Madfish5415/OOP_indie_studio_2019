# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté hello
project(helloIRR)

# Crée des variables avec les fichiers à compiler
set(SRCS
    src/main.cpp
    src/MapGenerator/MapGenerator.cpp
    )

set(HEADERS
    src/MapGenerator/MapGenerator.hpp
    )

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(main ${SRCS})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package (Irrlicht)

if (Irrlicht_FOUND)
    # Une fois la dépendance trouvée, nous l'incluons au projet
    target_include_directories(main PUBLIC ${Irrlicht_INCLUDE_DIRS})
    message(SUCCESS_MESSAGE "This is the include path ${Irrlicht_INCLUDE_DIRS}")
    target_link_libraries (main ${Irrlicht_LIBRARIES})
else ()
    # Sinon, nous affichons un message
    message(FATAL_ERROR "libIrrlicht not found")
endif ()