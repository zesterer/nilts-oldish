//----LOCAL----
#include "client.h"
#include "window.h"
#include "common/io.h"

namespace Nilts
{
	namespace Core
	{
		Client::Client()
		{
			IO::output("Creating Client");

			this->window = new Window();

			this->window->activate();
		}

		bool Client::run()
		{
			bool running = true;

			running &= this->window->refresh();

			if (!running)
			{
				this->window->close();
			}

            return running;
		}
	}
}
