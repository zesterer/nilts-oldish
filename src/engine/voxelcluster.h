#ifndef NILTS_ENGINE_VOXELCLUSTER_H
#define NILTS_ENGINE_VOXELCLUSTER_H

//----STANDARD----
#include "unordered_map"

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "voxelclusterchild.h"

namespace Nilts
{
	namespace Engine
	{
		struct MapKey
		{
			public:
				float x, y, z;
			
				bool operator==(const MapKey &other) const;
		};
		
		struct KeyHasher
		{
			public:
				std::size_t operator()(const MapKey& k) const;
		};
		
		class VoxelCluster
		{
			public:
				glm::ivec3 child_size;
				std::unordered_map<MapKey, VoxelClusterChild*, KeyHasher> children;
				
				VoxelCluster(glm::ivec3 child_size);
				VoxelClusterChild* getAt(glm::ivec3 pos);
				bool loadAt(glm::ivec3 pos);
			
			private:
				MapKey vecToKey(glm::ivec3 vec);
		};
	}
}

#endif
