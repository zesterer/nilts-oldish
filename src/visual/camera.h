#ifndef NILTS_VISUAL_CAMERA_H
#define NILTS_VISUAL_CAMERA_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"

//----LOCAL----
#include "common/types.h"
#include "core/window.h"

namespace Nilts
{
	namespace Visual
	{
		class Camera
		{
			public:
				/*
				The camera doesn't use my built-in matrix
				or state type because the tranformations
				required are rather different (not least
				because they're completely reversed).
				*/
				glm::vec3 position;
				glm::vec3 rotation;
				glm::mat4 matrix;
				glm::mat4 perspective_matrix;

				//For input - should be temporary!
				Core::Window* window;

				float32 fov = 0.95;
				float32 min_render = 0.01;
				float32 max_render = 100;

				Camera();
				void update();
				void grabInputs();
		};
	}
}

#endif // NILTS_VISUAL_CAMERA_H
