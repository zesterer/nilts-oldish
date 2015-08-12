//----LOCAL----
#include "renderer.h"
#include "scene.h"

namespace Nilts
{
	namespace Render
	{
		void Renderer::renderMeshObject(MeshObject* object)
		{
			if (this->mode != RenderMode::MESHOBJECT)
				this->setModeMesh();
			this->mode = RenderMode::MESHOBJECT;
			
			if (!object->mesh.buffered)
				object->mesh.buffer();
			
			object->shader->enable();
			
			//Bind the vertex buffer
			gl::glBindBuffer(gl::GL_ARRAY_BUFFER, object->mesh.gl_id);
			
			//Find the uniform camera matrix, then assign it
			gl::GLuint perspective_matrix_id = gl::glGetUniformLocation(object->shader->gl_id, "PERSPECTIVE_MATRIX");
			gl::glUniformMatrix4fv(perspective_matrix_id, 1, gl::GL_FALSE, &this->scene->realm->camera->perspective_matrix[0][0]);

			//Find the uniform camera matrix, then assign it
			gl::GLuint camera_matrix_id = gl::glGetUniformLocation(object->shader->gl_id, "CAMERA_MATRIX");
			gl::glUniformMatrix4fv(camera_matrix_id, 1, gl::GL_FALSE, &this->scene->realm->camera->matrix[0][0]);
			
			//Find the uniform model vector, then assign it
			gl::GLuint model_matrix_id = gl::glGetUniformLocation(object->shader->gl_id, "MODEL_MATRIX");
			gl::glUniformMatrix4fv(model_matrix_id, 1, gl::GL_FALSE, &object->state->matrix[0][0]);
			
			//Find the material, then assign it
			glm::vec4 material_data = glm::vec4(object->material->shininess, object->material->specular_amount, object->material->specular_cap, 0.0);
			gl::GLuint material_id = gl::glGetUniformLocation(object->shader->gl_id, "MATERIAL_DATA");
			gl::glUniform4fv(material_id, 1, &material_data.x);
			gl::glUniform1i(gl::glGetUniformLocation(object->shader->gl_id, "MATERIAL_EFFECTS"), object->material->effects);
			
			//Draw the model
			gl::glDrawArrays(object->mesh.mode, 0, object->mesh.polygons.size() * 3);
		}
		
		void Renderer::setModeMesh()
		{
			//Disable all the vertex attribute arrays again
			for (int count = 0; count < 4; count ++)
				gl::glDisableVertexAttribArray(count);
			
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
		}
	}
}
