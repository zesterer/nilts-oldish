#Specify the cmake version being used
cmake_minimum_required(VERSION 2.6)

#Require pkg-config to continue (Actually,
#we don't need it yet. But keep it commented for future)
#find_package(PkgConfig REQUIRED)




#
#   Nilts configuration
#

#Name of the project
project(nilts)

#Add a version number
set (NILTS_VERSION_MAJOR 0)
set (NILTS_VERSION_MINOR 0)
set (NILTS_VERSION_RELEASE 0)

#Turn on debug
set (NILTS_DEBUG_ENABLED true)

#Define a configuration file used by cmake
configure_file("${PROJECT_SOURCE_DIR}/src/main.h.in" "${PROJECT_BINARY_DIR}/main.h")




#
#   LIBRARIES
#

#Add GLFW
set(GLFW_BUILD_DOCS FALSE)
set(GLFW_BUILD_EXAMPLES FALSE)
add_subdirectory(extern-glfw)
include_directories("extern-glfw/include")

#Add GLBINDING
set(GLBINDING_BUILD_DOCS FALSE)
add_subdirectory(extern-glbinding)
include_directories("extern-glbinding/source/glbinding/include")

#Add GLM
set(GLM_BUILD_DOCS FALSE)
include_directories("extern-glm")




#
#   Source code
#

#All the directories containing header files
include_directories(
"${PROJECT_SOURCE_DIR}/src/"
"${PROJECT_SOURCE_DIR}/src/common/"
"${PROJECT_SOURCE_DIR}/src/core/"
"${PROJECT_SOURCE_DIR}/src/world/"
"${PROJECT_SOURCE_DIR}/src/micro/"
"${PROJECT_SOURCE_DIR}/src/engine/"
"${PROJECT_SOURCE_DIR}/src/game/"
"${PROJECT_SOURCE_DIR}/src/macro/"
"${PROJECT_SOURCE_DIR}/src/render/"
"${PROJECT_SOURCE_DIR}/src/render/structures/"
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
src/visual/data/framebuffer.cpp
src/core/inputmanager.cpp
src/engine/entity.cpp
src/engine/particle.cpp
src/engine/realm.cpp
src/engine/voxelcluster.cpp
src/engine/voxelfield.cpp
src/game/manager.cpp
src/engine/voxelterrain.cpp
src/engine/voxelclusterchild.cpp
src/render/structures/polygon.cpp
src/render/structures/material.cpp
src/render/structures/shader.cpp
src/render/structures/mesh.cpp
src/engine/metadata.cpp
src/render/scene.cpp
src/render/meshobject.cpp
src/render/renderable.cpp
src/render/voxelfieldobject.cpp
src/engine/camera.cpp
src/render/structures/framebuffer.cpp
src/render/renderer.cpp
)




#
#   Compilation options
#

#Build statically
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBRARIES OFF)
#SET(CMAKE_EXE_LINKER_FLAGS "-static")

#Tell the compiler to include -std=c++11
add_definitions(-g -std=c++11 -Wall)

#Add a location for a search path for headers
include_directories("${PROJECT_BINARY_DIR}")

#add_library(glfw STATIC IMPORTED)
#add_library(glbinding STATIC IMPORTED)




#
#   Compilation
#

#Take the code and turn it into the executable
add_executable(nilts ${SOURCE_FILES})

#Link the final executable to the needed libraries
target_link_libraries(nilts glfw glbinding ${GLFW_LIBRARIES})
