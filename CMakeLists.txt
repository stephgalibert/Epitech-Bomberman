cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_COMPILER  g++)
# SET ( CMAKE_CXX_FLAGS "-std=c++0x" CACHE STRING "compile flags" FORCE)
project(Bomberman)

# Enable testing for current directory and below.
enable_testing()

# The version number.
set (Bomberman_VERSION_MAJOR 1)
set (Bomberman_VERSION_MINOR 0)

# should we use our own math functions?
option (START_GTEST "Launch test instead of start the program" OFF)

IF (START_GTEST)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") # debug, no optimisation
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage") # enabling coverage
ENDIF (START_GTEST)

# Enable c++11 with CMake
add_compile_options(-std=c++11)
add_compile_options(-g)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/build_config.h.in"
  "${PROJECT_SOURCE_DIR}/source/build_config.h"
  )

# add search path for include files
include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/source
  ${PROJECT_SOURCE_DIR}/source/astar
  ${PROJECT_SOURCE_DIR}/source/binding
  ${PROJECT_SOURCE_DIR}/source/blocks
  ${PROJECT_SOURCE_DIR}/source/bombs
  ${PROJECT_SOURCE_DIR}/source/effects
  ${PROJECT_SOURCE_DIR}/source/environment
  ${PROJECT_SOURCE_DIR}/source/irrassimp
  ${PROJECT_SOURCE_DIR}/source/loader
  ${PROJECT_SOURCE_DIR}/source/music
  ${PROJECT_SOURCE_DIR}/source/players
  ${PROJECT_SOURCE_DIR}/source/powerups
  ${PROJECT_SOURCE_DIR}/source/utils
  ${PROJECT_SOURCE_DIR}/source/thread
  ${PROJECT_SOURCE_DIR}/source/ui
  ${PROJECT_SOURCE_DIR}/lib/irrlicht/include
  ${PROJECT_SOURCE_DIR}/lib/assimp/include
  ${PROJECT_SOURCE_DIR}/lib/lua/LuaBridge/
  ${PROJECT_SOURCE_DIR}/lib/lua/LuaBridge/detail
  ${PROJECT_SOURCE_DIR}/lib/lua/LuaInterpreter/include
  ${PROJECT_SOURCE_DIR}/lib/SFML/include/
  ${PROJECT_SOURCE_DIR}/lib/google-test/include/
  ${PROJECT_SOURCE_DIR}/lib/google-test/include/gtest
)

FILE(GLOB SRCS
    source/*.cpp
    source/*.hpp
    source/**/*.cpp
    source/**/*.hpp
  )

# call the CMakeList to build gtest.a
add_subdirectory(lib/google-test)

# add the executable
add_executable(bomberman ${SRCS})

# build static gtest library before target
add_dependencies(bomberman gtest)
# add unix libraries to the executable

if (UNIX)
  # Irrlicht must be linked first
  target_link_libraries(bomberman
    ${PROJECT_SOURCE_DIR}/lib/irrlicht/lib/linux/libIrrlicht.a
    ${PROJECT_SOURCE_DIR}/lib/lua/LuaInterpreter/lib/linux/liblua.a
    ${PROJECT_SOURCE_DIR}/lib/google-test/libgtest.a
    -lGL -lXxf86vm -lXext -lX11 -lpthread -ldl
    -Wl,-rpath,${PROJECT_SOURCE_DIR}/lib/assimp/lib/linux
    -Wl,-rpath,${PROJECT_SOURCE_DIR}/lib/google_test/lib
    -Wl,-rpath,${PROJECT_SOURCE_DIR}/lib/SFML/lib/linux
    -Wl,-rpath,${PROJECT_SOURCE_DIR}/lib/irrlicht/lib/linux/
    ${PROJECT_SOURCE_DIR}/lib/irrlicht/lib/linux/libXcursor.so
    ${PROJECT_SOURCE_DIR}/lib/assimp/lib/linux/libassimp.so
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/linux/libsfml-audio.so
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/linux/libsfml-system.so
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/linux/libopenal.so.1
  )
  file(COPY ${PROJECT_SOURCE_DIR}/asset DESTINATION ${PROJECT_SOURCE_DIR}/build)
  # override install path if it has not been explicitly specified
  set (CMAKE_INSTALL_PREFIX "../")
endif (UNIX)

# add window libraries to the executable
if (MSVC)
  target_link_libraries(bomberman
    ${PROJECT_SOURCE_DIR}/lib/assimp/lib/window/assimp-vc130-mt.lib
    ${PROJECT_SOURCE_DIR}/lib/irrlicht/lib/window/irrlicht.lib
    ${PROJECT_SOURCE_DIR}/lib/lua/LuaInterpreter/lib/window/lua5.3.0.lib
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/window/sfml-audio.lib
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/window/sfml-system.lib
  )

  file(COPY ${PROJECT_SOURCE_DIR}/asset DESTINATION ${PROJECT_SOURCE_DIR}/build)
  file(COPY ${PROJECT_SOURCE_DIR}/asset DESTINATION ${PROJECT_SOURCE_DIR}/build/Debug)
  file(COPY ${PROJECT_SOURCE_DIR}/lib/assimp/lib/window/assimp-vc130-mt.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/Debug)
  file(COPY ${PROJECT_SOURCE_DIR}/lib/irrlicht/lib/window/irrlicht.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/Debug)
  file(COPY ${PROJECT_SOURCE_DIR}/lib/lua/LuaInterpreter/lib/window/lua5.3.0.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/Debug)
  file(COPY ${PROJECT_SOURCE_DIR}/lib/SFML/lib/window/openal32.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/Debug)
  file(COPY ${PROJECT_SOURCE_DIR}/lib/SFML/lib/window/libsndfile-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/Debug)
  file(COPY ${PROJECT_SOURCE_DIR}/lib/SFML/lib/window/sfml-audio-2.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/Debug)
  file(COPY ${PROJECT_SOURCE_DIR}/lib/SFML/lib/window/sfml-system-2.dll DESTINATION ${PROJECT_SOURCE_DIR}/build/Debug)
endif (MSVC)

# add the install targets in bin directory
install (TARGETS bomberman DESTINATION bin)
install (DIRECTORY asset DESTINATION bin)

add_test(FullTest bomberman)

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/asset/installer/license.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Bomberman_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Bomberman_VERSION_MINOR}")
include (CPack)
