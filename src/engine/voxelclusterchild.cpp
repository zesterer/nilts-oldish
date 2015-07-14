//----LOCAL----
#include "voxelclusterchild.h"

namespace Nilts
{
	namespace Engine
	{
		VoxelClusterChild::VoxelClusterChild(glm::ivec3 pos, VoxelCluster* parent, glm::ivec3 size) : VoxelField(size)
		{
			this->pos = pos;
			this->parent = parent;
		}
	}
}
