//----STANDARD----
#include "string"

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

namespace Nilts
{
	namespace World
	{
		void Region::generate()
		{
			Generation::PerlinNoise noise;

			for (uint8 x = 0; x < NILTS_REGION_SIZE; x ++)
			{
				for (uint8 y = 0; y < NILTS_REGION_SIZE; y ++)
				{
					for (uint8 z = 0; z < NILTS_REGION_SIZE; z ++)
					{
						glm::vec4 pos = glm::vec4((float32)(this->pos.x + x), (float32)(this->pos.y + y), (float32)(this->pos.z + z), 3.0);
						if (noise.getPerlin(pos, 1.0, 3.0, 1.0) < 0.0)
							this->voxels[x][y][z].type = 1;
						else
							this->voxels[x][y][z].type = 0;
					}
				}
			}

			IO::output("Generated region at " + to_string(this->pos.x) + "," + to_string(this->pos.y) + "," + to_string(this->pos.z));
		}
	}
}
