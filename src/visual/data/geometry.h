#ifndef NILTS_VISUAL_DATA_GEOMETRY_H
#define NILTS_VISUAL_DATA_GEOMETRY_H

//----STANDARD----
#include "vector"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace std;
using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			struct Vertex
			{
				public:
					glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
					glm::vec3 col = glm::vec3(1.0, 1.0, 1.0);
					glm::vec2 tex = glm::vec2(-1.0, -1.0);
					glm::vec3 norm = glm::vec3(0.0, 0.0, 0.0);
			};

			struct Polygon
			{
				public:
					Vertex a, b, c;

					void correctNormals();
			};

			struct Face
            {
            	public:
					unsigned int a_pos, a_col, a_tex, a_norm;
					unsigned int b_pos, b_col, b_tex, b_norm;
					unsigned int c_pos, c_col, c_tex, c_norm;

					unsigned char has_parts;
            };

			class Mesh
			{
				public:
					vector<Polygon> polygons;
			};
		}
	}
}

#endif // NILTS_VISUAL_DATA_GEOMETRY_H
