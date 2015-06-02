#ifndef NILTS_VISUAL_DATA_SHADER_H
#define NILTS_VISUAL_DATA_SHADER_H

//----STANDARD---
#include "string"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

using namespace std;
using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			struct Shader
			{
				public:
					GLuint gl_id;

					void enable();
					void loadFromFiles(string vertex_file_path, string fragment_file_path);
					void loadFromStrings(string VertexShaderCode, string FragmentShaderCode);
			};
		}
	}
}

#endif // NILTS_VISUAL_DATA_SHADER_H
