#ifndef NILTS_VISUAL_CAMERA_H
#define NILTS_VISUAL_CAMERA_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"

//----LOCAL----
#include "common/types.h"

namespace Nilts
{
	namespace Visual
	{
		class Camera
		{
			public: glm::vec3 position;
			public: glm::vec3 rotation;
			public: glm::mat4 matrix;
			public: glm::mat4 perspective_matrix;

			public: float32 fov = 0.95;
			public: float32 min_render = 0.01;
			public: float32 max_render = 100;

			public: Camera();
			public: void update();
		};
	}
}

#endif // NILTS_VISUAL_CAMERA_H
