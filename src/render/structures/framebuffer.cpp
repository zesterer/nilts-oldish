//----LOCAL----
#include "framebuffer.h"
#include "common/io.h"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			FrameBuffer::FrameBuffer(int width, int height)
			{
				this->width = width;
				this->height = height;
				
				//Create the texture
				gl::glGenTextures(1, &this->gl_tex_id);
				//Bind the texture
				gl::glBindTexture(gl::GL_TEXTURE_2D, this->gl_tex_id);
				gl::glTexImage2D(gl::GL_TEXTURE_2D, 0, (gl::GLint)gl::GL_RGBA16F, this->width, this->height, 0, gl::GL_RGB, gl::GL_UNSIGNED_BYTE, 0);
				//Add filtering
				gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MAG_FILTER, (gl::GLint)gl::GL_NEAREST);
				gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MIN_FILTER, (gl::GLint)gl::GL_NEAREST);

				//Create the framebuffer
				gl::glGenFramebuffers(1, &this->gl_id);
				gl::glBindFramebuffer(gl::GL_FRAMEBUFFER, this->gl_id);
				gl::glFramebufferTexture2D(gl::GL_FRAMEBUFFER, gl::GL_COLOR_ATTACHMENT0, gl::GL_TEXTURE_2D, this->gl_tex_id, 0);

				//Create a depth buffer
				gl::glGenRenderbuffers(1, &this->gl_depth_id);
				//Bind the depth buffer
				gl::glBindRenderbuffer(gl::GL_RENDERBUFFER, this->gl_depth_id);
				gl::glRenderbufferStorage(gl::GL_RENDERBUFFER, gl::GL_DEPTH_COMPONENT, 640 * 1.4, 480 * 1.4);
				gl::glFramebufferRenderbuffer(gl::GL_FRAMEBUFFER, gl::GL_DEPTH_ATTACHMENT, gl::GL_RENDERBUFFER, this->gl_depth_id);

				//Configure the framebuffer
				//Set the render texture to colour attachment 0
				gl::glFramebufferTexture(gl::GL_FRAMEBUFFER, gl::GL_COLOR_ATTACHMENT0, this->gl_tex_id, 0);

				//Set the draw buffers
				this->setDrawBuffers();

				if (gl::glCheckFramebufferStatus(gl::GL_FRAMEBUFFER) == gl::GL_FRAMEBUFFER_COMPLETE)
					this->enabled = true;

				IO::test(this->enabled, "Creating Post-Processing FrameBuffer");

				//Create the screen quad
				gl::glGenVertexArrays(1, &this->gl_quad_array_id);
				gl::glBindVertexArray(this->gl_quad_array_id);

				const gl::GLfloat gl_quad_data[] =
				{
					-1.0, -1.0,  0.0,
					 1.0, -1.0,  0.0,
					-1.0,  1.0,  0.0,
					-1.0,  1.0,  0.0,
					 1.0, -1.0,  0.0,
					 1.0,  1.0,  0.0,
				};

				gl::glGenBuffers(1, &this->gl_quad_buffer_id);
				gl::glBindBuffer(gl::GL_ARRAY_BUFFER, this->gl_quad_buffer_id);
				gl::glBufferData(gl::GL_ARRAY_BUFFER, sizeof(gl_quad_data), gl_quad_data, gl::GL_STATIC_DRAW);

				this->shader = new Shader();
				this->shader->loadFromFiles("../shaders/framebuffer-vertex-shader.glsl", "../shaders/framebuffer-fragment-shader.glsl");
			}
			
			void FrameBuffer::setDrawBuffers()
			{
				//Set the list of draw buffers
				this->gl_draw_buffers[0] = gl::GL_COLOR_ATTACHMENT0;
				gl::glDrawBuffers(1, this->gl_draw_buffers);
			}
			
			void FrameBuffer::render()
			{
				//Disable backface culling
				gl::glDisable(gl::GL_CULL_FACE);

				//Disable the depth buffer
				gl::glDisable(gl::GL_DEPTH_TEST);
				gl::glDepthFunc(gl::GL_NONE);

				//Bind the framebuffer ready
				gl::glBindFramebuffer(gl::GL_FRAMEBUFFER, 0);
				gl::glViewport(0, 0, this->width, this->height); // Render on the whole framebuffer, complete from the lower left corner to the upper right

				gl::glBindBuffer(gl::GL_ARRAY_BUFFER, this->gl_quad_buffer_id);

				//Tell the shaders what different parts of the buffer mean using the above array
				gl::glEnableVertexAttribArray(0);
				gl::glVertexAttribPointer(0, 3, gl::GL_FLOAT, gl::GL_FALSE, sizeof(gl::GLfloat) * 3, (void*)(unsigned long)0);

				gl::GLuint tex_id = gl::glGetUniformLocation(this->shader->gl_id, "RENDER_TEXTURE");
				gl::glUniform1i(tex_id, 0);
				gl::glBindTexture(gl::GL_TEXTURE_2D, this->gl_tex_id);

				this->shader->enable();

				gl::glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

				gl::glDrawArrays(gl::GL_TRIANGLES, 0, sizeof(gl::GLfloat) * 6 * 3);

				gl::glDisableVertexAttribArray(0);
				
				//IO::output("Rendered framebuffer");
			}
		}
	}
}
