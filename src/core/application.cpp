//----LOCAL----
#include "application.h"
#include "micro/world.h"
#include "common/io.h"

namespace Nilts
{
	namespace Core
	{
		Application::Application(AppConfig* config)
		{
			IO::output("Creating Application");

			if (!config->server_not_client) //We should be running the client
				this->client = new Client();
		}

		int Application::run()
		{
			while (this->running)
			{
				this->running &= this->client->run();
			}

            return 0;
		}
	}
}
