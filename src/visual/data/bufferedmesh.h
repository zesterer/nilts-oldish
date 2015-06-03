#ifndef NILTS_VISUAL_DATA_BUFFEREDMESH_H
#define NILTS_VISUAL_DATA_BUFFEREDMESH_H

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

//----LOCAL----
#include "geometry.h"

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			class BufferedMesh : public Mesh
			{
				public:
					GLuint gl_id;
					GLenum mode = GL_TRIANGLES;
					bool buffered;

					BufferedMesh();
					bool loadFromOBJ(string filename);
					void buffer();
			};
		}
	}
}

#endif // NILTS_VISUAL_DATA_BUFFEREDMESH_H
