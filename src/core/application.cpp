//----LOCAL----
#include "application.h"
#include "micro/world.h"

namespace Nilts
{
	namespace Core
	{
		Application::Application(AppConfig* config)
		{
			this->world = new Micro::World();
		}

		int Application::run()
		{
            return 0;
		}
	}
}
