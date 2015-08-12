#ifndef NILTS_RENDER_STRUCTURES_FRAMEBUFFER_H
#define NILTS_RENDER_STRUCTURES_FRAMEBUFFER_H

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "shader.h"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			class FrameBuffer
			{
				public:
					gl::GLuint gl_id;
					gl::GLuint gl_tex_id;
					gl::GLuint gl_depth_id;

					gl::GLuint gl_quad_array_id;
					gl::GLuint gl_quad_buffer_id;

					gl::GLenum gl_draw_buffers[1];
					
					int width, height;

					bool enabled = false;

					Shader* shader;

					FrameBuffer(int width, int height);
					void render();
					void setDrawBuffers();
			};
		}
	}
}

#endif
