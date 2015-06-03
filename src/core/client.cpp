//----LOCAL----
#include "client.h"
#include "window.h"
#include "common/io.h"
#include "visual/scene.h"
#include "world/world.h"

namespace Nilts
{
	namespace Core
	{
		Client::Client()
		{
			IO::output("Creating Client");

			this->world = new World::World();

			this->window = new Window();
			this->window->enable();

			this->scene = new Visual::Scene();
			this->scene->camera->window = this->window;
			this->scene->enable();
		}

		void Client::close()
		{
			this->window->close();
			IO::output("Closed Client");
		}

		bool Client::run()
		{
			bool running = true;

			//Tick the world
			this->world->tick();

			//Render the scene
			this->scene->render();

			//Refresh the window
			running &= this->window->refresh();

			if (!running) //If the client should close
				this->close();

            return running;
		}
	}
}
