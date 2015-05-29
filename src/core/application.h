#ifndef NILTS_CORE_APPLICATION_H
#define NILTS_CORE_APPLICATION_H

//----LOCAL----
#include "world/world.h"

//----STANDARD----
#include "string"
#include "vector"

using namespace std;

namespace Nilts
{
	namespace Core
	{
		struct AppConfig
		{
			//Should we be running a console server?
			bool server_not_client = false;
		};

		class Application
		{
			vector<string> args;

			World::World* world;

			public: Application(AppConfig* config);
			public: int run();
		};
	}
}

#endif // NILTS_CORE_APPLICATION_H
