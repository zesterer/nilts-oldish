#ifndef NILTS_WORLD_TERRAIN_TERRAIN_H
#define NILTS_WORLD_TERRAIN_TERRAIN_H

//----STANDARD----
#include "map"
#include "vector"

//----LOCAL----
#include "world/position.h"
#include "common/task.h"

//How big is each chunk?
#define REGION_SIZE 32

using namespace std;

namespace Nilts
{
	namespace World
	{
		namespace Terrain
		{
			typedef unsigned char uint8;

			struct Voxel
			{
				public:
					uint8 type;
					uint8 data;
			};

            struct Region
            {
				public:
					VoxelPos pos;
					Voxel voxels[REGION_SIZE][REGION_SIZE][REGION_SIZE];
					long offset[REGION_SIZE][REGION_SIZE];

            	public:
					void generate(Task::Priority priority = Task::NORMAL);
            };

            //This struct is used as the hashing function for the voxel position
            /*struct HashVoxelPos
			{
				size_t operator()(const VoxelPos &x) const
				{
					return hash<long>()(x.x) ^ hash<long>()(x.y) ^ hash<long>()(x.z);
				}
			};*/

            class Terrain
            {
            	public:
            		map<VoxelPos, Region> regions;

				private:
					vector<VoxelPos> region_queue;

				public:
					void loadRegion(VoxelPos pos, Task::Priority priority = Task::NORMAL);
            };
		}
	}
}

#endif // NILTS_WORLD_TERRAIN_TERRAIN_H
