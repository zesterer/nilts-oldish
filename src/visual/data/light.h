#ifndef NILTS_VISUAL_DATA_LIGHT_H
#define NILTS_VISUAL_DATA_LIGHT_H

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

#include "glm/glm.hpp"
#include "glm/vec3.hpp"

using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			enum LightType
			{
				DIRECTIONAL,
				POINT
			};

			struct Light
			{
				public: LightType type;
				public: glm::vec3 position;
				public: glm::vec3 colour;
				public: GLfloat ambiance;
			};
		}
	}
}

#endif // NILTS_VISUAL_DATA_LIGHT_H
