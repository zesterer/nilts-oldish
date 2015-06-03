#ifndef NILTS_WORLD_ENTITY_H
#define NILTS_WORLD_ENTITY_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "common/types.h"

namespace Nilts
{
	 namespace World
	 {
	 	class Entity
	 	{
	 		public:
				glm::vec3 pos;
	 	};
	 }
}

#endif // NILTS_WORLD_ENTITY_H
