#ifndef NILTS_RENDER_STRUCTURES_MESH_H
#define NILTS_RENDER_STRUCTURES_MESH_H

//----STANDARD----
#include "vector"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "polygon.h"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			class Mesh
			{
				public:
					std::vector<Polygon> polygons;
					
					bool buffered;
					GLuint gl_id;
					GLenum mode = GL_TRIANGLES;
					
					bool loadFromOBJ(string filename);
					void buffer();
			}
		}
	}
}

#endif
