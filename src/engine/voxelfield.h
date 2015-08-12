#ifndef NILTS_ENGINE_VOXELFIELD_H
#define NILTS_ENGINE_VOXELFIELD_H

//----STANDARD----
#include "vector"

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "voxel.h"
#include "metadata.h"

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
				
				//The metadata associated with this voxelfield.
				//For example, this may contain renderer polygon data
				MetaData* render_metadata = nullptr;
				MetaData* game_metadata = nullptr;
				
				VoxelField(glm::ivec3 size);
				Voxel* getAt(glm::ivec3 pos);
		};
	}
}

#endif
