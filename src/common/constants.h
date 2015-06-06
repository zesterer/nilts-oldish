#ifndef NILTS_COMMON_CONSTANTS_H
#define NILTS_COMMON_CONSTANTS_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//World data
#define NILTS_REGION_SIZE 256

//Cube vectors. For face placement and stuff
#define CubeVec000 glm::vec3(0.0, 0.0, 0.0)
#define CubeVec001 glm::vec3(0.0, 0.0, 1.0)
#define CubeVec010 glm::vec3(0.0, 1.0, 0.0)
#define CubeVec011 glm::vec3(0.0, 1.0, 1.0)

#define CubeVec100 glm::vec3(1.0, 0.0, 0.0)
#define CubeVec101 glm::vec3(1.0, 0.0, 1.0)
#define CubeVec110 glm::vec3(1.0, 1.0, 0.0)
#define CubeVec111 glm::vec3(1.0, 1.0, 1.0)

#endif // NILTS_COMMON_CONSTANTS_H
