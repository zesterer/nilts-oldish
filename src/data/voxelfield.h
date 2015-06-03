#ifndef NILTS_DATA_VOXELFIELD_H
#define NILTS_DATA_VOXELFIELD_H

//----STANDARD----
#include "vector"

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "common/types.h"

using namespace std;

namespace Nilts
{
	namespace Data
	{
		struct Voxel
		{
			public:
				uint16 data = 0;
		};

		class VoxelField
		{
			public:
				IntVec3 dimensions;
				vector<Voxel> voxels;

				//For testing the empty areas
				Voxel space;

				VoxelField(IntVec3 dimensions);
				Voxel* getVoxel(IntVec3 pos);
		};
	}
}

#endif // NILTS_DATA_VOXELFIELD_H
