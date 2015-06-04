//----STANDARD----
#include "string"
#include "vector"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

//----LOCAL----
#include "scene.h"
#include "camera.h"
#include "common/io.h"
#include "data/object.h"
#include "data/geometry.h"
#include "data/bufferedmesh.h"
#include "data/material.h"
#include "data/light.h"
#include "data/shader.h"
#include "common/types.h"
#include "camera.h"
#include "data/meshedvoxelfield.h"

using namespace std;
using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		Scene::Scene()
		{
			IO::output("Creating Application");

			this->camera = new Camera();
		}

		void Scene::enable()
		{
			IO::output("Initialising GLBinding");
			glbinding::Binding::initialize();

			//Enable backface culling
			glEnable(GL_CULL_FACE);

			//Enable the depth buffer
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);

			//Create the shader
			this->shader = new Data::Shader();
			this->shader->loadFromFiles("../shaders/std-vertex-shader.glsl", "../shaders/std-fragment-shader.glsl");
			this->shader->enable();

			Data::Light sun;
			sun.type = Data::LightType::DIRECTIONAL;
			sun.colour = {0.2, 0.2, 0.2};
			sun.position = {1.0, 1.0, -1.0};
			sun.ambiance = 0.0;
			this->lights.push_back(sun);

			Data::Light othersun;
			othersun.type = Data::LightType::DIRECTIONAL;
			othersun.colour = {0.5, 0.5, 0.4};
			othersun.position = {-1.0, -1.0, -1.0};
			othersun.ambiance = 0.15;
			this->lights.push_back(othersun);

			static Data::Object* object = new Data::Object();
			object->update();
			this->registerObject(object);

			static Nilts::Data::MeshedVoxelField* field = new Nilts::Data::MeshedVoxelField({256, 256, 128});
			field->extract();
			object->material->shininess = 5.0;
			object->mesh = field->mesh;

		}

		void Scene::render()
		{
			//Update stuff
			this->update();

			//Blank the screen
			glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//What is the buffer array composed of?
			int length[] = {sizeof(glm::vec3), sizeof(glm::vec3), sizeof(glm::vec2), sizeof(glm::vec3)};

			//Loop through the objects and draw each one
			for (auto iter = this->objects.begin(); iter != this->objects.end(); iter ++)
			{
				Data::Object* object = *iter;
				Data::BufferedMesh* mesh = object->mesh;
				Data::Material* material = object->material;

				//Buffer the mesh if it's not already been done
				if (!mesh->buffered)
					mesh->buffer();

				//Bind the vertex buffer
				glBindBuffer(GL_ARRAY_BUFFER, mesh->gl_id);

				//Bind the texture buffer
				//glBindTexture(GL_TEXTURE_2D, texture->gl_id);

				//Enable the shader
				this->shader->enable();

				//Tell the shaders what different parts of the buffer mean using the above array
				GLuint offset = 0;
				for (GLuint array_id = 0; array_id < 4; array_id ++)
				{
					glEnableVertexAttribArray(array_id);
					glVertexAttribPointer(array_id, length[array_id] / sizeof(GLfloat), GL_FLOAT, GL_FALSE, sizeof(Data::Vertex), (void*)(unsigned long)offset);
					offset += length[array_id];
				}

				//Find the tick, then assign it
				GLuint tick_id = glGetUniformLocation(this->shader->gl_id, "TICK");
				glUniform1ui(tick_id, 0);

				//Find the uniform camera matrix, then assign it
				GLuint perspective_matrix_id = glGetUniformLocation(this->shader->gl_id, "PERSPECTIVE_MATRIX");
				glUniformMatrix4fv(perspective_matrix_id, 1, GL_FALSE, &this->camera->perspective_matrix[0][0]);

				//Find the uniform camera matrix, then assign it
				GLuint camera_matrix_id = glGetUniformLocation(this->shader->gl_id, "CAMERA_MATRIX");
				glUniformMatrix4fv(camera_matrix_id, 1, GL_FALSE, &this->camera->matrix[0][0]);

				//Find the uniform model vector, then assign it
				GLuint model_matrix_id = glGetUniformLocation(this->shader->gl_id, "MODEL_MATRIX");
				glUniformMatrix4fv(model_matrix_id, 1, GL_FALSE, &object->matrix.matrix[0][0]);

				//Find the material, then assign it
				glm::vec4 material_data = glm::vec4(material->shininess, material->specular_amount, material->specular_cap, 0.0);
				GLuint material_id = glGetUniformLocation(this->shader->gl_id, "MATERIAL_DATA");
				glUniform4fv(material_id, 1, &material_data.x);

				glUniform1i(glGetUniformLocation(this->shader->gl_id, "MATERIAL_EFFECTS"), material->effects);

				this->assignLights();

				//Draw the model
				glDrawArrays(mesh->mode, 0, mesh->polygons.size() * 3);

				//Disable all the vertex attribute arrays again
				for (int count = 0; count < 4; count ++)
					glDisableVertexAttribArray(count);
			}
		}

		void Scene::update()
		{
			this->camera->update();
		}

		void Scene::assignLights()
		{
			//Find the uniform lighting vector, then assign it
			glm::vec4 light_vector_array[16];
			glm::vec4 light_colour_array[16];

			for (unsigned int light = 0; light < this->lights.size(); light ++)
			{
				Data::Light* clight = &this->lights[light];

				if (clight->type == Data::LightType::DIRECTIONAL)
					light_vector_array[light] = glm::vec4(clight->position, 0.0);
				else
					light_vector_array[light] = glm::vec4(clight->position, 1.0);

				light_colour_array[light] = glm::vec4(clight->colour, clight->ambiance);
			}

			glUniform4fv(glGetUniformLocation(this->shader->gl_id, "LIGHT_VECTOR"), 16 * 3, &light_vector_array[0].x);
			glUniform4fv(glGetUniformLocation(this->shader->gl_id, "LIGHT_COLOUR"), 16 * 3, &light_colour_array[0].x);
		}

		void Scene::registerObject(Data::Object* object)
		{
			this->objects.insert(object);
		}

		void Scene::deregisterObject(Data::Object* object)
		{
			this->objects.erase(object);
		}
	}
}
