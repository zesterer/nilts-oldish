#ifndef NILTS_ENGINE_VOXELCLUSTERCHILD_H
#define NILTS_ENGINE_VOXELCLUSTERCHILD_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "voxelentity.h"

namespace Nilts
{
	namespace Engine
	{
		class VoxelCluster;
		
		class VoxelClusterChild : public VoxelField
		{
			public:
				glm::ivec3 pos;
				VoxelCluster* parent;
				
				VoxelClusterChild(glm::ivec3 pos, VoxelCluster* parent, glm::ivec3 size);
		};
	}
}

#endif
