//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "world.h"
#include "common/constants.h"

using namespace std;

namespace Nilts
{
	namespace World
	{
		World::World()
		{
			this->current_tick = 0;
		}

		void World::tick()
		{
			this->current_tick ++;
		}

		void World::loadRegion(glm::ivec3 pos)
		{
			Region region;
			region.pos = pos;
			this->regions.push_back(region);
		}

		bool World::regionLoaded(glm::ivec3 pos)
		{
			for (uint16 count = 0; count < this->regions.size(); count ++)
			{
				if (this->regions[count].pos == pos)
				{
					return true;
				}
			}

			return false;
		}
	}
}
