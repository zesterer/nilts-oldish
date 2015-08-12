//----LOCAL----
#include "voxelfieldobject.h"
#include "common/io.h"
#include "structures/vertex.h"

namespace Nilts
{
	namespace Render
	{
		VoxelFieldObject::VoxelFieldObject(Engine::Realm* realm, Engine::VoxelField* parent)
		{
			this->realm = realm;
			this->parent = parent;
			
			this->shader = new Structures::Shader();
			this->shader->loadFromFiles("../shaders/std-vertex-shader.glsl", "../shaders/std-fragment-shader.glsl");
			
			this->material = new Structures::Material(3.0, 1.0);
			
			this->mesh.loadFromOBJ("../koopa.obj");
		}
		
		void VoxelFieldObject::render(State* state, Structures::FrameBuffer* framebuffer)
		{
			//Buffer the mesh if it's not already been done
			if (!this->mesh.buffered)
				this->mesh.buffer();
			
			this->shader->enable();
			
			//Bind the vertex buffer
			gl::glBindBuffer(gl::GL_ARRAY_BUFFER, this->mesh.gl_id);
			
			//What is the buffer array composed of?
			int length[] = {sizeof(glm::vec3), sizeof(glm::vec3), sizeof(glm::vec2), sizeof(glm::vec3)};
			
			//Tell the shaders what different parts of the buffer mean using the above array
			gl::GLuint offset = 0;
			for (gl::GLuint array_id = 0; array_id < 4; array_id ++)
			{
				gl::glEnableVertexAttribArray(array_id);
				gl::glVertexAttribPointer(array_id, length[array_id] / sizeof(gl::GLfloat), gl::GL_FLOAT, gl::GL_FALSE, sizeof(Structures::Vertex), (void*)(unsigned long)offset);
				offset += length[array_id];
			}
			
			//Find the uniform camera matrix, then assign it
			gl::GLuint perspective_matrix_id = gl::glGetUniformLocation(this->shader->gl_id, "PERSPECTIVE_MATRIX");
			gl::glUniformMatrix4fv(perspective_matrix_id, 1, gl::GL_FALSE, &this->realm->camera->perspective_matrix[0][0]);

			//Find the uniform camera matrix, then assign it
			gl::GLuint camera_matrix_id = gl::glGetUniformLocation(this->shader->gl_id, "CAMERA_MATRIX");
			gl::glUniformMatrix4fv(camera_matrix_id, 1, gl::GL_FALSE, &this->realm->camera->matrix[0][0]);
			
			//Find the uniform model vector, then assign it
			gl::GLuint model_matrix_id = gl::glGetUniformLocation(this->shader->gl_id, "MODEL_MATRIX");
			gl::glUniformMatrix4fv(model_matrix_id, 1, gl::GL_FALSE, &state->matrix[0][0]);
			
			//Find the material, then assign it
			glm::vec4 material_data = glm::vec4(this->material->shininess, this->material->specular_amount, this->material->specular_cap, 0.0);
			gl::GLuint material_id = gl::glGetUniformLocation(this->shader->gl_id, "MATERIAL_DATA");
			gl::glUniform4fv(material_id, 1, &material_data.x);
			gl::glUniform1i(gl::glGetUniformLocation(this->shader->gl_id, "MATERIAL_EFFECTS"), this->material->effects);
			
			//Define the texture that should be rendered to
			//gl::GLuint tex_id = gl::glGetUniformLocation(framebuffer->shader->gl_id, "RENDER_TEXTURE");
			//gl::glUniform1i(tex_id, 0);
			//gl::glBindTexture(gl::GL_TEXTURE_2D, framebuffer->gl_tex_id);
			
			//Draw the model
			gl::glDrawArrays(this->mesh.mode, 0, this->mesh.polygons.size() * 3);

			//Disable all the vertex attribute arrays again
			for (int count = 0; count < 4; count ++)
				gl::glDisableVertexAttribArray(count);
		}
	}
}
