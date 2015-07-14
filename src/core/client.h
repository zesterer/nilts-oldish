#ifndef NILTS_CORE_CLIENT_H
#define NILTS_CORE_CLIENT_H

//----LOCAL----
#include "window.h"
#include "visual/scene.h"
#include "world/world.h"
#include "game/manager.h"
#include "inputmanager.h"

namespace Nilts
{
	namespace Core
	{
		class Client
		{
			public:
				Window* window;
				
				InputManager* inputmanager;
				Game::Manager* manager;

				Visual::Scene* scene;

				Client();
				void close();
				bool run();
		};
	}
}

#endif // NILTS_CORE_CLIENT_H
