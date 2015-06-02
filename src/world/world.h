#ifndef NILTS_WORLD_WORLD_H
#define NILTS_WORLD_WORLD_H

//----STANDARD----
#include "map"
#include "forward_list"

//----LOCAL----
#include "common/types.h"
#include "common/constants.h"
#include "entity.h"
#include "visual/data/geometry.h"

using namespace std;

namespace Nilts
{
	namespace Micro
	{
		struct Voxel
		{
			public:
				uint16 type;
		};

		struct Region
		{
			public:
				IntPos pos;
				Voxel voxels[NILTS_REGION_SIZE][NILTS_REGION_SIZE][NILTS_REGION_SIZE];
				Visual::Data::Mesh* mesh;
		};

		class World
		{
			public:
				map<IntPos, Region> regions;
				forward_list<Entity> entities;

				uint32 tick;

				World();
				void tick();
		};
	}
}

#endif // NILTS_WORLD_WORLD_H
