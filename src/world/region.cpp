//----STANDARD----
#include "string"
#include <algorithm>

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

//----LOCAL----
#include "region.h"
#include "common/types.h"
#include "common/constants.h"
#include "common/io.h"
#include "generation/perlin.h"
#include "data/meshedvoxelfield.h"

using namespace std;

namespace Nilts
{
	namespace World
	{
		Region::Region()
		{
			//Initialise the components
			this->field = new Data::MeshedVoxelField(glm::ivec3(NILTS_REGION_SIZE, NILTS_REGION_SIZE, NILTS_REGION_SIZE));
			this->object = new Visual::Data::Object();

			//Link the meshes together by deleting the object's old mesh and patching in the voxelfield's one
			delete this->object->mesh;
			this->object->mesh = this->field->mesh;

			//Set the material properties
			this->object->material->shininess = 3.0;
			this->object->material->specular_amount = 1.0;
		}

		void Region::generate()
		{
			World::Generation::PerlinNoise noise;

			//Loop through each voxel
			glm::ivec3 count = {0, 0, 0};
			for (count.x = 0; count.x < this->field->size.x; count.x ++)
			{
				for (count.y = 0; count.y < this->field->size.y; count.y ++)
				{
					for (count.z = 0; count.z < this->field->size.z; count.z ++)
					{
						Data::Voxel* voxel = this->field->getVoxel(count);
						glm::vec3 pos = glm::vec3((float32)(count.x + this->pos.x), (float32)(count.y + this->pos.y), (float32)(count.z + this->pos.z));

						///*
						glm::vec2 offset = noise.getPerlinVec2(glm::vec4(pos.x, pos.y, pos.z, 7.0), -7.5, 1.0, 1.0);

						if ((noise.getPerlin(glm::vec4((pos.x + 96.0 * offset.x), (pos.y + 96.0 * offset.y), 0.0, 2.0), -8.5, 2.0, 1.0) + 3.0) * 48.0 > pos.z)
							voxel->data = 1;

						if (voxel->data == 1 && true)
						{
							float32 p1 = noise.getPerlin(glm::vec4(pos.x, pos.y, pos.z, 56.0), -9.0, 2.0, 1.5);
							float32 p2 = noise.getPerlin(glm::vec4(pos.x, pos.y, pos.z, 156.0), -9.0, 2.0, 1.5);

							if ((1.0 - glm::abs(p1)) * (1.0 - glm::abs(p2)) > 0.93)
								voxel->data = 0;
						}

						voxel->density = voxel->data;
						//*/
						/*
						voxel->density = max(noise.getPerlin(glm::vec4(pos.x, pos.y, pos.z, 2.0), -7.5, 2.0, 1.0), 0.0f);
						//IO::output(to_string(voxel->density));

						if (voxel->density != 0)
							voxel->data = 1;
						//*/
					}
				}
			}

			IO::output("Generated region at " + to_string(this->pos.x) + "," + to_string(this->pos.y) + "," + to_string(this->pos.z));
		}
	}
}
