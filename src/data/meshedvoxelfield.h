#ifndef NILTS_DATA_MESHEDVOXELFIELD_H
#define NILTS_DATA_MESHEDVOXELFIELD_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

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
			/*
			A class derived from VoxelField designed to represent both
			a 3D voxel field and a it's accompanying polygon mesh.
			*/

			public:
				Visual::Data::BufferedMesh* mesh;

				MeshedVoxelField(glm::ivec3 size);
				void extract();

			private:
				void addQuad(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d);
		};
	}
}

#endif // NILTS_DATA_MESHEDVOXELFIELD_H
