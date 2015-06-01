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
				glm::vec3 pos;
				glm::vec3 col;
				glm::vec2 tex;
				glm::vec3 norm;
			};

			struct Polygon
			{
				Vertex a, b, c;
			};

			class Mesh
			{
				vector<Polygon> polygons;
			};
		}
	}
}

#endif // NILTS_VISUAL_DATA_GEOMETRY_H
