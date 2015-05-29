//----LOCAL----
#include "application.h"
#include "world/world.h"

namespace Nilts
{
	namespace Core
	{
		Application::Application(AppConfig* config)
		{
			this->world = new World::World();
		}

		int Application::run()
		{
            return 0;
		}
	}
}
