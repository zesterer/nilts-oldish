#ifndef NILTS_RENDER_STRUCTURES_SHADER_H
#define NILTS_RENDER_STRUCTURES_SHADER_H

//----STANDARD----
#include "string"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			struct Shader
			{
				public:
					gl::GLuint gl_id;

					void loadFromFiles(std::string vertex_file_path, std::string fragment_file_path);
					void loadFromStrings(std::string VertexShaderCode, std::string FragmentShaderCode);
			};
		}
	}
}

#endif
