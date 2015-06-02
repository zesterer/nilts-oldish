//----LOCAL----
#include "client.h"
#include "window.h"
#include "common/io.h"
#include "visual/scene.h"

namespace Nilts
{
	namespace Core
	{
		Client::Client()
		{
			IO::output("Creating Client");

			this->window = new Window();
			this->window->enable();

			this->scene = new Visual::Scene();
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
