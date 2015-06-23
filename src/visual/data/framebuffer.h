#ifndef NILTS_VISUAL_DATA_FRAMEBUFFER_H
#define NILTS_VISUAL_DATA_FRAMEBUFFER_H

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			class FrameBuffer
			{
				public:
					GLuint gl_id;
					GLuint gl_tex_id;
					GLuint gl_depth_id;

					GLenum gl_draw_buffers[1];

					bool enabled = false;

					FrameBuffer();
			};
		}
	}
}

#endif // NILTS_VISUAL_DATA_FRAMEBUFFER_H
