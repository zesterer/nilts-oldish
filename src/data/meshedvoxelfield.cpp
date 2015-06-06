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
#include "marchingcubestable.h"

using namespace std;

namespace Nilts
{
	namespace Data
	{
		MeshedVoxelField::MeshedVoxelField(glm::ivec3 size) : VoxelField(size)
		{
			this->mesh = new Visual::Data::BufferedMesh();
		}

		void MeshedVoxelField::extract(MeshingAlgorithm algorithm) //Extract a mesh from the voxel field
		{
			IO::output("Extracting mesh from voxel field of size " + to_string(this->size.x * this->size.y * this->size.z));

			//Clear before meshing takes place
			this->mesh->polygons.clear();

			switch (algorithm)
			{
				case (MeshingAlgorithm::Cubic):
				{
					this->extractCubic();
					break;
				}

				case (MeshingAlgorithm::MarchingCubes):
				{
					this->extractMarchingCubes(true);
					break;
				}

				case (MeshingAlgorithm::SurfaceNets):
				{
					this->extractMarchingCubes(false);
					break;
				}
			}
		}

		void MeshedVoxelField::extractCubic()
		{
			//Loop through each voxel
			glm::ivec3 count = {0, 0, 0};
			for (count.x = 0; count.x < this->size.x; count.x ++)
			{
				for (count.y = 0; count.y < this->size.y; count.y ++)
				{
					for (count.z = 0; count.z < this->size.z; count.z ++)
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

		void MeshedVoxelField::extractMarchingCubes(bool use_density)
		{
            //Loop through each voxel
			glm::ivec3 count = {0, 0, 0};
			for (count.x = 0; count.x < this->size.x; count.x ++)
			{
				for (count.y = 0; count.y < this->size.y; count.y ++)
				{
					for (count.z = 0; count.z < this->size.z; count.z ++)
					{
						glm::vec3 pos = glm::vec3((float32)count.x, (float32)count.y, (float32)count.z);

						//Find the configuration index based on surrounding voxels
						uint8 index = 0;
						if (this->getVoxel(count + glm::ivec3(0, 0, 0))->density > 0) index |= 0b00000001;
						if (this->getVoxel(count + glm::ivec3(1, 0, 0))->density > 0) index |= 0b00000010;
						if (this->getVoxel(count + glm::ivec3(1, 1, 0))->density > 0) index |= 0b00000100;
						if (this->getVoxel(count + glm::ivec3(0, 1, 0))->density > 0) index |= 0b00001000;
						if (this->getVoxel(count + glm::ivec3(0, 0, 1))->density > 0) index |= 0b00010000;
						if (this->getVoxel(count + glm::ivec3(1, 0, 1))->density > 0) index |= 0b00100000;
						if (this->getVoxel(count + glm::ivec3(1, 1, 1))->density > 0) index |= 0b01000000;
						if (this->getVoxel(count + glm::ivec3(0, 1, 1))->density > 0) index |= 0b10000000;

						uint8 density_cube[8];
						density_cube[0] = this->getVoxel(count + glm::ivec3(0, 0, 0))->density;
						density_cube[1] = this->getVoxel(count + glm::ivec3(0, 0, 1))->density;
						density_cube[2] = this->getVoxel(count + glm::ivec3(0, 1, 0))->density;
						density_cube[3] = this->getVoxel(count + glm::ivec3(0, 1, 1))->density;
						density_cube[4] = this->getVoxel(count + glm::ivec3(1, 0, 0))->density;
						density_cube[5] = this->getVoxel(count + glm::ivec3(1, 0, 1))->density;
						density_cube[6] = this->getVoxel(count + glm::ivec3(1, 1, 0))->density;
						density_cube[7] = this->getVoxel(count + glm::ivec3(1, 1, 1))->density;

						//Get the configuration
						vector<Visual::Data::Polygon> polygons = this->getMarchingCubesPolygonConfiguration(index, &density_cube[0], use_density);

						//Move all those polygons to their correct position in the mesh
						for (uint8 poly = 0; poly < polygons.size(); poly ++)
						{
							polygons[poly].a.pos += pos;
							polygons[poly].b.pos += pos;
							polygons[poly].c.pos += pos;
						}

						//Append them all to the current mesh
						this->mesh->polygons.insert(this->mesh->polygons.end(), polygons.begin(), polygons.end());
					}
				}
			}
		}

		float32 MeshedVoxelField::getOffset(uint8 d1, uint8 d2)
		{
			float32 v1 = ((float32)d1) / 256.0;
			float32 v2 = ((float32)d2) / 256.0;
			float32 delta = v2 - v1;
			return 0.5 + delta * 0.5;
		}

		vector<Visual::Data::Polygon> MeshedVoxelField::getMarchingCubesPolygonConfiguration(uint8 index, uint8* density, bool use_density)
		{
			vector<Visual::Data::Polygon> polygons;
			int triangles[16];

			//Place the triangle array into the triangles
			for (uint8 c = 0; c < 16; c ++)
			{
				triangles[c] = MC_TRITABLE[index][c];
			}

			//Add the polygons
			for (uint8 c = 0; c < 15; c += 3)
			{
				if (triangles[c] != -1)
				{
					Visual::Data::Polygon poly;

					if (use_density)
					{
						poly.c.pos = glm::mix(MC_EDGES[triangles[c + 0]][0], MC_EDGES[triangles[c + 0]][1], this->getOffset(density[MC_EDGE2VERTEX[triangles[c + 0]][0]], density[MC_EDGE2VERTEX[triangles[c + 0]][1]]));
						poly.b.pos = glm::mix(MC_EDGES[triangles[c + 1]][0], MC_EDGES[triangles[c + 1]][1], this->getOffset(density[MC_EDGE2VERTEX[triangles[c + 1]][0]], density[MC_EDGE2VERTEX[triangles[c + 1]][1]]));
						poly.a.pos = glm::mix(MC_EDGES[triangles[c + 2]][0], MC_EDGES[triangles[c + 2]][1], this->getOffset(density[MC_EDGE2VERTEX[triangles[c + 2]][0]], density[MC_EDGE2VERTEX[triangles[c + 2]][1]]));
					}
					else
					{
						poly.c.pos = glm::mix(MC_EDGES[triangles[c + 0]][0], MC_EDGES[triangles[c + 0]][1], 0.5);
						poly.b.pos = glm::mix(MC_EDGES[triangles[c + 1]][0], MC_EDGES[triangles[c + 1]][1], 0.5);
						poly.a.pos = glm::mix(MC_EDGES[triangles[c + 2]][0], MC_EDGES[triangles[c + 2]][1], 0.5);
					}

					poly.correctNormals();

					polygons.push_back(poly);
				}
			}

			return polygons;
		}
	}
}
