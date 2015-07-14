#ifndef NILTS_ENGINE_VOXELFIELD_H
#define NILTS_ENGINE_VOXELFIELD_H

//----STANDARD----
#include "vector"

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "voxel.h"

namespace Nilts
{
	namespace Engine
	{
		class VoxelField
		{
			public:
				//The field dimensions
				glm::ivec3 size;
				//The field contents
				std::vector<Voxel> voxels;
				
				//The default external voxel
				Voxel empty;
				
				VoxelField(glm::ivec3 size);
				Voxel* getAt(glm::ivec3 pos);
		};
	}
}

#endif
