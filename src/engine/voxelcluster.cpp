//----LOCAL----
#include "voxelcluster.h"
#include "common/io.h"

namespace Nilts
{
	namespace Engine
	{
		bool MapKey::operator==(const MapKey &other) const
		{
			return (other.x == this->x && other.y == this->y && other.z == this->z);
		}
		
		std::size_t KeyHasher::operator()(const MapKey& k) const
		{
			return ((std::hash<float>()(k.x) ^ (std::hash<float>()(k.y) << 1)) >> 1) ^ (std::hash<float>()(k.z) << 1);
		}
		
		VoxelCluster::VoxelCluster(glm::ivec3 child_size)
		{
			this->child_size = child_size;
		}
		
		MapKey VoxelCluster::vecToKey(glm::ivec3 vec)
		{
			MapKey temp;
			temp.x = vec.x;
			temp.y = vec.y;
			temp.z = vec.z;
			return temp;
		}
		
		VoxelClusterChild* VoxelCluster::getAt(glm::ivec3 pos)
		{
			return this->children.at(this->vecToKey(pos));
		}
		
		bool VoxelCluster::loadAt(glm::ivec3 pos)
		{
			if (this->children.count(this->vecToKey(pos)) > 0)
				return false;
			
			VoxelClusterChild* tmp = new VoxelClusterChild(pos, this, this->child_size);
			this->children.insert({this->vecToKey(pos), tmp});
			
			IO::output("Loaded region!");
			
			return true;
		}
	}
}
