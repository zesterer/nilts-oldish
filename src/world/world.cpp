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
			for (int16 x = -4; x < 4; x ++)
			{
				for (int16 y = -4; y < 4; y ++)
				{
					for (int16 z = -4; z < 4; z ++)
					{
                        IntPos pos;
                        pos.x = (this->camera.x / NILTS_REGION_SIZE) * NILTS_REGION_SIZE + x * NILTS_REGION_SIZE;
                        pos.y = (this->camera.y / NILTS_REGION_SIZE) * NILTS_REGION_SIZE + y * NILTS_REGION_SIZE;
                        pos.z = (this->camera.z / NILTS_REGION_SIZE) * NILTS_REGION_SIZE + z * NILTS_REGION_SIZE;

						if (!this->regionLoaded(pos))
						{
							this->loadRegion(pos);
						}
					}
				}
			}

			this->current_tick ++;
		}

		void World::loadRegion(IntPos pos)
		{
			Region region;
			region.pos = pos;
			this->regions.push_back(region);
		}

		bool World::regionLoaded(IntPos pos)
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
