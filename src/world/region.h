#ifndef NILTS_WORLD_REGION_H
#define NILTS_WORLD_REGION_H

//----LOCAL----
#include "visual/data/object.h"
#include "common/types.h"
#include "common/constants.h"

namespace Nilts
{
	namespace World
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

				bool generated = false;

				Visual::Data::Object* object = nullptr;

				void generate();
		};
	}
}

#endif // NILTS_WORLD_REGION_H
