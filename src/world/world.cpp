//----LOCAL----
#include "world.h"

namespace Nilts
{
	namespace World
	{
		World::World()
		{
			this->tick = 0;
		}

		void World::tick()
		{
			this->tick ++;
		}
	}
}
