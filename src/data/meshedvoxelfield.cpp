//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

//----LOCAL----
#include "meshedvoxelfield.h"
#include "voxelfield.h"
#include "visual/data/bufferedmesh.h"
#include "common/types.h"
#include "common/constants.h"
#include "visual/data/geometry.h"
#include "common/io.h"

#include "world/generation/perlin.h"

using namespace std;

namespace Nilts
{
	namespace Data
	{
		MeshedVoxelField::MeshedVoxelField(IntVec3 dimensions) : VoxelField(dimensions)
		{
			this->mesh = new Visual::Data::BufferedMesh();
		}

		void MeshedVoxelField::extract() //Extract a mesh from the voxel field
		{
			IO::output("Extracting mesh from voxel field of size " + to_string(this->dimensions.sum()));

			World::Generation::PerlinNoise noise;

			//Loop through each voxel
			IntVec3 count = {0, 0, 0};
			for (count.x = 0; count.x < this->dimensions.x; count.x ++)
			{
				for (count.y = 0; count.y < this->dimensions.y; count.y ++)
				{
					for (count.z = 0; count.z < this->dimensions.z; count.z ++)
					{
						Voxel* voxel = this->getVoxel(count);
						glm::vec3 pos = glm::vec3((float32)count.x, (float32)count.y, (float32)count.z);

						glm::vec3 offset = glm::normalize(noise.getPerlinVector(glm::vec4(pos.x / 500.0, pos.y / 500.0, pos.z / 500.0, 7.0), 2.0, 3.0, 1.5));

						if ((noise.getPerlin(glm::vec4((pos.x + 32.0 * offset.x) / 1000.0, (pos.y + 32.0 * offset.y) / 1000.0, 0.0 * offset.z, 2.0), 1.0, 3.0, 1.0) + 1.1) * 32.0 > pos.z)
							voxel->data = 1;
					}
				}
			}

			//Loop through each voxel
			count = {0, 0, 0};
			for (count.x = 0; count.x < this->dimensions.x; count.x ++)
			{
				for (count.y = 0; count.y < this->dimensions.y; count.y ++)
				{
					for (count.z = 0; count.z < this->dimensions.z; count.z ++)
					{
						Voxel* voxel = this->getVoxel(count);

						glm::vec3 pos = glm::vec3((float32)count.x, (float32)count.y, (float32)count.z);

						if (voxel->data != 0)
						{
							//Bottom
							if (this->getVoxel({count.x, count.y, count.z - 1})->data <= 0)
								this->addQuad(pos + CubeVec100, pos + CubeVec110, pos + CubeVec010, pos + CubeVec000);
							//Top
							if (this->getVoxel({count.x, count.y, count.z + 1})->data <= 0)
								this->addQuad(pos + CubeVec001, pos + CubeVec011, pos + CubeVec111, pos + CubeVec101);
							//Left
							if (this->getVoxel({count.x - 1, count.y, count.z})->data <= 0)
								this->addQuad(pos + CubeVec000, pos + CubeVec010, pos + CubeVec011, pos + CubeVec001);
							//Right
							if (this->getVoxel({count.x + 1, count.y, count.z})->data <= 0)
								this->addQuad(pos + CubeVec101, pos + CubeVec111, pos + CubeVec110, pos + CubeVec100);
							//Back
							if (this->getVoxel({count.x, count.y - 1, count.z})->data <= 0)
								this->addQuad(pos + CubeVec000, pos + CubeVec001, pos + CubeVec101, pos + CubeVec100);
							//Front
							if (this->getVoxel({count.x, count.y + 1, count.z})->data <= 0)
								this->addQuad(pos + CubeVec110, pos + CubeVec111, pos + CubeVec011, pos + CubeVec010);
						}
					}
				}
			}
		}

		void MeshedVoxelField::addQuad(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d)
		{
			Visual::Data::Polygon p1, p2;

			p1.a.pos = a;
			p1.b.pos = c;
			p1.c.pos = b;

			p2.a.pos = d;
			p2.b.pos = c;
			p2.c.pos = a;

			p1.correctNormals();
			p2.correctNormals();

			this->mesh->polygons.push_back(p1);
			this->mesh->polygons.push_back(p2);
		}
	}
}
