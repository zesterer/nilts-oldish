#ifndef NILTS_RENDER_STRUCTURES_MESH_H
#define NILTS_RENDER_STRUCTURES_MESH_H

//----STANDARD----
#include "vector"
#include "string"

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
					
					bool buffered = false;
					gl::GLuint gl_id;
					gl::GLenum mode = gl::GL_TRIANGLES;
					
					bool loadFromOBJ(std::string filename);
					void buffer();
			};
		}
	}
}

#endif
