#ifndef NILTS_WORLD_GENERATION_PERLIN_H
#define NILTS_WORLD_GENERATION_PERLIN_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

//----LOCAL----
#include "common/types.h"

namespace Nilts
{
	namespace World
	{
		namespace Generation
		{
			struct PerlinNoise
			{
				float32 getRandom(glm::vec4 pos);

				float32 getNoise(glm::vec4 pos, float32 octave);

				float32 getPerlin(glm::vec4 pos, float32 initial, float32 octaves, float32 skip);

				glm::vec3 getPerlinVector(glm::vec4 pos, float32 initial, float32 octaves, float32 skip);
			};
		}
	}
}

#endif // NILTS_WORLD_GENERATION_PERLIN_H
