#
# A CMake module to find SFML for the project B-YEP-400 IndieStudio
#
# This CMake module is designed to work on Fedora28 and Windows10. We will not
# provide support for other distributions. We will use this module to compile
# your project during our tests.
#
# You must provide the path to this module to CMake by setting
# CMAKE_MODULE_PATH variable to its location.
#
# Once done this module will define:
#  SFML_FOUND - system has SFML
#  SFML_INCLUDE_DIRS - the SFML include directory
#  SFML_LIBRARIES - Link these to use SFML
#
# Author: Guillaume DEVOILLE <guillaume1.devoille@epitech.eu> (17/05/2019)
#

IF (NOT SFML_INCLUDE_DIRS OR NOT SFML_LIBRARIES)
  FIND_PATH(SFML_INCLUDE_DIRS
    NAMES
      SFML/
    PATHS
      /usr/include/             # Default Fedora28 system include path
      /usr/local/include/       # Default Fedora28 local include path
      ${CMAKE_MODULE_PATH}/include/ # Expected to contain the path to this file for Windows10
      ${SFML_DIR}/include/      # SFML root directory (if provided)
  )

  IF (MSVC)     # Windows
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
  ELSE (MSVC)   # Linux
    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
  ENDIF(MSVC)

  FIND_LIBRARY(SFML_LIBRARIES
    NAMES
      sfml-audio
    PATHS
      /usr/lib64/                   # Default Fedora28 library path
      /usr/lib/                     # Some more Linux library path
      /usr/lib/x86_64-linux-gnu/    # Some more Linux library path
      /usr/local/lib/               # Some more Linux library path
      /usr/local/lib64/             # Some more Linux library path
      ${CMAKE_MODULE_PATH}/         # Expected to contain the path to this file for Windows10
      ${SFML_DIR}/                  # SFML root directory (if provided)
  )
ENDIF (NOT SFML_INCLUDE_DIRS OR NOT SFML_LIBRARIES)

IF (SFML_INCLUDE_DIRS AND SFML_LIBRARIES)
  SET(SFML_FOUND TRUE)
ELSE (SFML_INCLUDE_DIRS AND SFML_LIBRARIES)
  SET(SFML_FOUND FALSE)
ENDIF (SFML_INCLUDE_DIRS AND SFML_LIBRARIES)

IF (SFML_FIND_REQUIRED AND NOT SFML_FOUND)
  MESSAGE(FATAL_ERROR
    "  SFML not found.\n"
    "      Windows: Fill CMake variable CMAKE_MODULE_PATH to the provided directory.\n"
    "      Linux: Install SFML using your package manager ($> sudo dnf install SFML-devel).\n"
  )
ENDIF (SFML_FIND_REQUIRED AND NOT SFML_FOUND)
