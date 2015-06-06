//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "voxelfield.h"
#include "common/types.h"

namespace Nilts
{
	namespace Data
	{
		VoxelField::VoxelField(glm::ivec3 size)
		{
			this->voxels.reserve(size.x * size.y * size.z);

			for (int32 count = 0; count < size.x * size.y * size.z; count ++)
				this->voxels.push_back(Voxel());

			this->size = size;
		}

		Voxel* VoxelField::getVoxel(glm::ivec3 pos)
		{
			if (pos.x < 0 || pos.x >= this->size.x)
				return &this->space;
			if (pos.y < 0 || pos.y >= this->size.y)
				return &this->space;
			if (pos.z < 0 || pos.z >= this->size.z)
				return &this->space;

			int32 slice = this->size.y * this->size.z;
			int32 depth = this->size.z;

			return &this->voxels[slice * pos.x + depth * pos.y + pos.z];
		}
	}
}
