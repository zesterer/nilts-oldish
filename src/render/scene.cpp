//----LOCAL----
#include "scene.h"
#include "common/io.h"
#include "voxelfieldobject.h"

namespace Nilts
{
	namespace Render
	{
		Scene::Scene(Engine::Realm* realm)
		{
			IO::output("Created the scene renderer!");
			this->realm = realm;
			
			this->renderer.scene = this;
			
			this->enable();
		}
		
		void Scene::enable()
		{
			IO::output("Initialising GLBinding");
			glbinding::Binding::initialize();
			
			//Set up the render buffer
			this->render_buffer = new Structures::FrameBuffer(640 * 1.4, 480 * 1.4);
		}
		
		void Scene::tick()
		{
			this->render();
		}
		
		void Scene::preRenderSetup()
		{
			//Enable backface culling
			gl::glEnable(gl::GL_CULL_FACE);

			//Enable the depth buffer
			gl::glEnable(gl::GL_DEPTH_TEST);
			gl::glDepthFunc(gl::GL_LESS);

			// Render to our framebuffer
			gl::glBindFramebuffer(gl::GL_FRAMEBUFFER, this->render_buffer->gl_id);
			gl::glViewport(0, 0, 640 * 1.4, 480 * 1.4);

			//Blank the screen
			gl::glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
			gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);
		}
		
		void Scene::render()
		{
			//Set up the environment for rendering
			this->preRenderSetup();
			
			//Loop through the terrain
			for (auto pair : this->realm->terrain->children)
			{
				VoxelFieldObject* object = (VoxelFieldObject*)pair.second->render_metadata;
				
				if (object != nullptr)
				{
					this->realm->terrain->state.scale = glm::vec3(0.0005f, 0.0005f, 0.0005f);
					this->realm->terrain->state.update();
					this->renderer.renderMeshObject(object);
				}
				else
				{
					IO::output("Detected orphaned object without render object");
					
					//Give it a renderer object
					pair.second->render_metadata = new VoxelFieldObject(this->realm, pair.second);
				}
			}
			
			//Render the resulting framebuffer with post-processing
			this->render_buffer->render();
			
			//IO::output("Rendered the scene!");
		}
	}
}
