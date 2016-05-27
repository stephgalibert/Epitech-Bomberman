cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_COMPILER  clang++)
# SET ( CMAKE_CXX_FLAGS "-std=c++0x" CACHE STRING "compile flags" FORCE)
project(Bomberman)

# The version number.
set (Bomberman_VERSION_MAJOR 1)
set (Bomberman_VERSION_MINOR 0)

# Enable c++11 with CMake
add_compile_options(-std=c++11)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/build_config.h.in"
  "${PROJECT_BINARY_DIR}/build_config.h"
  )

# add search path for include files
include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/source
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
  ${PROJECT_SOURCE_DIR}/lib/irrlicht/include
  ${PROJECT_SOURCE_DIR}/lib/assimp/include
  ${PROJECT_SOURCE_DIR}/lib/lua/LuaBridge/
  ${PROJECT_SOURCE_DIR}/lib/lua/LuaBridge/detail
  ${PROJECT_SOURCE_DIR}/lib/lua/LuaInterpreter/include
  ${PROJECT_SOURCE_DIR}/lib/SFML/include/
  ${PROJECT_SOURCE_DIR}/lib/google_test/include/
  ${PROJECT_SOURCE_DIR}/lib/google_test/include/gtest
)

FILE(GLOB SRCS
    source/*.cpp
    source/*.hpp
    source/**/*.cpp
    source/**/*.hpp
  )

# add the executable
add_executable(bomberman ${SRCS})

# add unix libraries to the executable
if (UNIX)
  # Irrlicht must be linked first
  target_link_libraries(bomberman
    ${PROJECT_SOURCE_DIR}/lib/irrlicht/lib/linux/libIrrlicht.a
    ${PROJECT_SOURCE_DIR}/lib/lua/LuaInterpreter/lib/linux/liblua.a
    -lGL -lXxf86vm -lXext -lX11 -lXcursor -lpthread -ldl
    -Wl,-rpath,${PROJECT_SOURCE_DIR}/lib/assimp/lib/linux
    -Wl,-rpath,${PROJECT_SOURCE_DIR}/lib/google_test/lib
    -Wl,-rpath,${PROJECT_SOURCE_DIR}/lib/SFML/lib/linux
    ${PROJECT_SOURCE_DIR}/lib/google_test/lib/libgtest.so
    ${PROJECT_SOURCE_DIR}/lib/assimp/lib/linux/libassimp.so
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/linux/libsfml-audio.so
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/linux/libsfml-system.so
  )
  file(COPY ${PROJECT_SOURCE_DIR}/asset DESTINATION ${PROJECT_SOURCE_DIR}/build)
endif (UNIX)

# add window libraries to the executable
if (MSVC)
  #TODO: Copy all dll with exe
  target_link_libraries(bomberman
    ${PROJECT_SOURCE_DIR}/lib/irrlicht/lib/window/irrlicht.lib
    ${PROJECT_SOURCE_DIR}/lib/assimp/lib/lib/assimp-vc130-mtd.lib
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/window/sfml-audio-d.lib
    ${PROJECT_SOURCE_DIR}/lib/SFML/lib/window/sfml-system-d.lib
  )
endif (MSVC)

# override install path if it has not been explicitly specified
set (CMAKE_INSTALL_PREFIX "../")

# add the install targets in bin directory
install (TARGETS bomberman DESTINATION bin)
install (DIRECTORY asset DESTINATION bin)

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/asset/installer/license.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Bomberman_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Bomberman_VERSION_MINOR}")
include (CPack)
