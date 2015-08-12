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
			
			this->inputmanager = new InputManager();
			
			this->window = new Window(this->inputmanager);
			this->window->enable();
			
			this->manager = new Game::Manager(this->inputmanager);

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

			//Tick the game
			//this->manager->tick();
			//this->manager->realm->camera->keys(this->window);

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
