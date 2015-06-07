#Specify the cmake version being used
cmake_minimum_required(VERSION 2.6)

#Require pkg-config to continue
find_package(PkgConfig REQUIRED)

#Add a version number
set (NILTS_VERSION_MAJOR 0)
set (NILTS_VERSION_MINOR 0)
set (NILTS_VERSION_RELEASE 0)

#Turn on debug
set (NILTS_DEBUG_ENABLED true)

#Name of the project
project(nilts)

#Tell the compiler to include -std=c++11
add_definitions(-std=c++11 -Wall)

#Libraries that can be imported with pkg-config
pkg_search_module(GLFW REQUIRED glfw3)
include_directories("${PROJECT_SOURCE_DIR}/glfw/include/")
include_directories("${PROJECT_SOURCE_DIR}/glfw/include/GLFW")
include_directories("glfw/include/")
include_directories(${GLFW_INCLUDE_DIRS})
add_subdirectory("${PROJECT_SOURCE_DIR}/glfw/src/")
add_subdirectory("glfw/")

#Define a configuration file used by cmake
configure_file("${PROJECT_SOURCE_DIR}/src/main.h.in" "${PROJECT_BINARY_DIR}/main.h")

#Add a location for a search path for headers
include_directories("${PROJECT_BINARY_DIR}")

#All the directories containing header files
include_directories(
"${PROJECT_SOURCE_DIR}/src/"
"${PROJECT_SOURCE_DIR}/src/common/"
"${PROJECT_SOURCE_DIR}/src/core/"
"${PROJECT_SOURCE_DIR}/src/world/"
"${PROJECT_SOURCE_DIR}/src/micro/"
)

set(SOURCE_FILES
src/main.cpp
src/core/application.cpp
src/core/window.cpp
src/common/io.cpp
src/core/client.cpp
src/visual/camera.cpp
src/visual/scene.cpp
src/common/types.cpp
src/visual/data/shader.cpp
src/visual/data/bufferedmesh.cpp
src/visual/data/material.cpp
src/visual/data/object.cpp
src/world/generation/perlin.cpp
src/world/region.cpp
src/world/world.cpp
src/data/voxelfield.cpp
src/data/meshedvoxelfield.cpp
src/visual/data/geometry.cpp
)

#Take the code and turn it into the executable
add_executable(nilts ${SOURCE_FILES})

#Link the final executable to the needed libraries
target_link_libraries(nilts glfw ${GLFW3_LIBRARY_DIR})
target_link_libraries(nilts glbinding ${GLBINDING_LIBRARY_DIR})
