//----LOCAL----
#include "voxelfield.h"
#include "common/types.h"

namespace Nilts
{
	namespace Data
	{
		VoxelField::VoxelField(IntVec3 dimensions)
		{
			for (int32 count = 0; count < dimensions.sum(); count ++)
				this->voxels.push_back(Voxel());

			this->dimensions = dimensions;
		}

		Voxel* VoxelField::getVoxel(IntVec3 pos)
		{
			if (pos.x < 0 || pos.x >= this->dimensions.x)
				return &this->space;
			if (pos.y < 0 || pos.y >= this->dimensions.y)
				return &this->space;
			if (pos.z < 0 || pos.z >= this->dimensions.z)
				return &this->space;

			int32 slice = this->dimensions.y * this->dimensions.z;
			int32 depth = this->dimensions.z;

			return &this->voxels[slice * pos.x + depth * pos.y + pos.z];
		}
	}
}
