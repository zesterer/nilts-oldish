#ifndef NILTS_WORLD_WORLD_H
#define NILTS_WORLD_WORLD_H

//----STANDARD----
#include "vector"
#include "forward_list"

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
		class World
		{
			public:
				IntPos camera;

				vector<Region> regions;
				forward_list<Entity> entities;

				uint32 current_tick;

				World();
				void tick();
				bool regionLoaded(IntPos pos);
				void loadRegion(IntPos pos);
		};
	}
}

#endif // NILTS_WORLD_WORLD_H
