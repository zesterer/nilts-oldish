#ifndef NILTS_WORLD_REGION_H
#define NILTS_WORLD_REGION_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "visual/data/object.h"
#include "common/types.h"
#include "common/constants.h"
#include "data/meshedvoxelfield.h"

namespace Nilts
{
	namespace World
	{
		class Region
		{
			public:
				glm::ivec3 pos;
				bool generated = false;

				Data::MeshedVoxelField* field;
				Visual::Data::Object* object;

				Region();
				void generate();
		};
	}
}

#endif // NILTS_WORLD_REGION_H
