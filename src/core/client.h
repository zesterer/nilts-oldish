#ifndef NILTS_CORE_CLIENT_H
#define NILTS_CORE_CLIENT_H

//----LOCAL----
#include "window.h"
#include "visual/scene.h"
#include "world/world.h"

namespace Nilts
{
	namespace Core
	{
		class Client
		{
			public:
				World::World* world;

				Window* window;

				Visual::Scene* scene;

				Client();
				void close();
				bool run();
		};
	}
}

#endif // NILTS_CORE_CLIENT_H
