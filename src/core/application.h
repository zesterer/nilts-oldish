#ifndef NILTS_CORE_APPLICATION_H
#define NILTS_CORE_APPLICATION_H

//----STANDARD----
#include "string"
#include "vector"

//----LOCAL----
#include "micro/world.h"
#include "client.h"

using namespace std;

namespace Nilts
{
	namespace Core
	{
		struct AppConfig
		{
			public:
				//Should we be running a console server?
				bool server_not_client = false;
		};

		class Application
		{
			public:
				vector<string> args;
				bool running = true;

				Client* client;

				Application(AppConfig* config);
				int run();
		};
	}
}

#endif // NILTS_CORE_APPLICATION_H
