#ifndef NILTS_DATA_MESHEDVOXELFIELD_H
#define NILTS_DATA_MESHEDVOXELFIELD_H

//----LOCAL----
#include "voxelfield.h"
#include "visual/data/bufferedmesh.h"
#include "common/types.h"

namespace Nilts
{
	namespace Data
	{
		class MeshedVoxelField : public VoxelField
		{
			public:
				Visual::Data::BufferedMesh* mesh;

				MeshedVoxelField(IntVec3 dimensions);
				void extract();

			private:
				void addQuad(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d);
		};
	}
}

#endif // NILTS_DATA_MESHEDVOXELFIELD_H
