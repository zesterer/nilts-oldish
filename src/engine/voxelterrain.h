#ifndef NILTS_ENGINE_VOXELTERRAIN_H
#define NILTS_ENGINE_VOXELTERRAIN_H

//----LOCAL----
#include "voxelcluster.h"
#include "entity.h"

namespace Nilts
{
	namespace Engine
	{
		class VoxelTerrain : public VoxelCluster, public Entity
		{
			public:
				VoxelTerrain(glm::ivec3 child_size);
		};
	}
}

#endif
