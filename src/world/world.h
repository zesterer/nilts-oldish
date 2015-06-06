#ifndef NILTS_WORLD_WORLD_H
#define NILTS_WORLD_WORLD_H

//----STANDARD----
#include "vector"
#include "forward_list"

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "common/types.h"
#include "common/constants.h"
#include "entity.h"
#include "region.h"
#include "visual/data/object.h"

using namespace std;

namespace Nilts
{
	namespace World
	{
		class RegionMap
		{
			public:
				vector<Region*> regions;
				Region* get(glm::ivec3 );
		};

		class World
		{
			public:
				vector<Region> regions;
				forward_list<Entity> entities;

				uint32 current_tick;

				World();
				void tick();
				bool regionLoaded(glm::ivec3 pos);
				void loadRegion(glm::ivec3 pos);
		};
	}
}

#endif // NILTS_WORLD_WORLD_H
