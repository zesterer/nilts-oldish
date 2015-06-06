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
				uint8 density = 0;
		};

		class VoxelField
		{
			/*
			A class designed to represent a 3D voxel field
			*/

			public:
				glm::ivec3 size;
				vector<Voxel> voxels;

				//The default null (external) voxel
				Voxel space;

				VoxelField(glm::ivec3 size);
				Voxel* getVoxel(glm::ivec3 pos);
		};
	}
}

#endif // NILTS_DATA_VOXELFIELD_H
