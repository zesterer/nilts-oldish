#ifndef NILTS_RENDER_STRUCTURES_VERTEX_H
#define NILTS_RENDER_STRUCTURES_VERTEX_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			struct Vertex
			{
				public:
					glm::vec3 pos  = glm::vec3(0.0, 0.0, 0.0);
					glm::vec3 col  = glm::vec3(1.0, 1.0, 1.0);
					glm::vec2 tex  = glm::vec2(-1.0, -1.0);
					glm::vec3 norm = glm::vec3(0.0, 0.0, 0.0);
			};
		}
	}
}

#endif
