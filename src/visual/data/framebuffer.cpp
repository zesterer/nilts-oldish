//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "framebuffer.h"
#include "common/io.h"

using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			FrameBuffer::FrameBuffer()
			{
				//Create the framebuffer
				glGenFramebuffers(1, &this->gl_id);
				glBindFramebuffer(GL_FRAMEBUFFER, this->gl_id);


				//Create the texture
				glGenTextures(1, &this->gl_tex_id);
				//Bind the texture
				glBindTexture(GL_TEXTURE_2D, this->gl_tex_id);
				glTexImage2D(GL_TEXTURE_2D, 0, (GLint)GL_RGB8UI, 1024, 768, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
				//Add filtering
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (GLint)GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (GLint)GL_NEAREST);


				//Create a depth buffer
				glGenRenderbuffers(1, &this->gl_depth_id);
				//Bind the depth buffer
				glBindRenderbuffer(GL_RENDERBUFFER, this->gl_depth_id);
				glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, 1024, 768);
				glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, this->gl_depth_id);

				//Configure the framebuffer
				//Set the render texture to colour attachment 0
				glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, this->gl_tex_id, 0);
				//Set the list of draw buffers
				this->gl_draw_buffers[0] = GL_COLOR_ATTACHMENT0;

				if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
					this->enabled = true;

				IO::test(this->enabled, "Creating Post-Processing FrameBuffer");
			}
		}
	}
}
