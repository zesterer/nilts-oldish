#ifndef NILTS_DATA_MESHEDVOXELFIELD_H
#define NILTS_DATA_MESHEDVOXELFIELD_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "voxelfield.h"
#include "visual/data/bufferedmesh.h"
#include "common/types.h"
#include "visual/data/geometry.h"

namespace Nilts
{
	namespace Data
	{
		enum MeshingAlgorithm
		{
			Cubic,
			MarchingCubes,
			SurfaceNets
		};

		class MeshedVoxelField : public VoxelField
		{
			/*
			A class derived from VoxelField designed to represent both
			a 3D voxel field and a it's accompanying polygon mesh.
			*/

			public:
				Visual::Data::BufferedMesh* mesh;

				MeshedVoxelField(glm::ivec3 size);
				void extract(MeshingAlgorithm algorithm = Cubic);

			private:
				void extractCubic();
				void extractMarchingCubes(bool use_density = false);
				float32 getOffset(uint8 d1, uint8 d2);
				vector<Visual::Data::Polygon> getMarchingCubesPolygonConfiguration(uint8 index, uint8* density, bool use_density);
				void addQuad(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d);
		};
	}
}

#endif // NILTS_DATA_MESHEDVOXELFIELD_H
