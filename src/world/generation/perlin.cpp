//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

//----LOCAL----
#include "perlin.h"
#include "common/types.h"

namespace Nilts
{
	namespace World
	{
		namespace Generation
		{
			float32 PerlinNoise::getRandom(glm::vec4 pos)
			{
				float32 val = glm::fract(glm::sin(glm::dot(pos, glm::vec4(3.1415, 12.9898, 78.233, 5.327)))* 43758.5453);
				return val;
			}

			float32 PerlinNoise::getNoise(glm::vec4 pos, float32 octave)
			{
				pos *= glm::pow(2.0, octave);
				glm::vec3 mpos = glm::mod(glm::vec3(pos.x, pos.y, pos.z), 1.0f);
				pos = glm::floor(pos);

				float32 c000 = this->getRandom(pos + glm::vec4(0.0, 0.0, 0.0, 0.0));
				float32 c100 = this->getRandom(pos + glm::vec4(1.0, 0.0, 0.0, 0.0));
				float32 c010 = this->getRandom(pos + glm::vec4(0.0, 1.0, 0.0, 0.0));
				float32 c110 = this->getRandom(pos + glm::vec4(1.0, 1.0, 0.0, 0.0));

				float32 c001 = this->getRandom(pos + glm::vec4(0.0, 0.0, 1.0, 0.0));
				float32 c101 = this->getRandom(pos + glm::vec4(1.0, 0.0, 1.0, 0.0));
				float32 c011 = this->getRandom(pos + glm::vec4(0.0, 1.0, 1.0, 0.0));
				float32 c111 = this->getRandom(pos + glm::vec4(1.0, 1.0, 1.0, 0.0));

				float32 eX00 = glm::mix(c000, c100, mpos.x);
				float32 eX10 = glm::mix(c010, c110, mpos.x);
				float32 eX01 = glm::mix(c001, c101, mpos.x);
				float32 eX11 = glm::mix(c011, c111, mpos.x);

				float32 fXX0 = glm::mix(eX00, eX10, mpos.y);
				float32 fXX1 = glm::mix(eX01, eX11, mpos.y);

				float32 value = glm::mix(fXX0, fXX1, mpos.z);

				return 2.0 * (value - 0.5);
			}

			float32 PerlinNoise::getPerlin(glm::vec4 pos, float32 initial, float32 octaves, float32 skip)
			{
				float32 val = 0.0;

				for (float32 x = initial; x < initial + octaves; x += skip)
					val += this->getNoise(pos, x + 2.0) / glm::pow(2.0, x - initial);

				return val;
			}
		}
	}
}
