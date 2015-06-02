//----STANDARD----
#include "string"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "scene.h"
#include "camera.h"
#include "common/io.h"
#include "data/object.h"

using namespace std;
using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		Scene::Scene()
		{
			IO::output("Creating Application");
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
			this->shader.loadFromFiles("../shaders/std-vertex-shader.glsl", "../shaders/std-fragment-shader.glsl");
			this->shader.enable();
		}

		void Scene::render()
		{
			//Blank the screen
			glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Scene::registerObject(Data::Object* object)
		{
			this->active_objects.insert(object);
		}

		void Scene::deregisterObject(Data::Object* object)
		{
			this->active_objects.erase(object);
		}
	}
}
