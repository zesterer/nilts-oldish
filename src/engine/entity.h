#ifndef NILTS_ENGINE_ENTITY_H
#define NILTS_ENGINE_ENTITY_H

//----LOCAL----
#include "common/types.h"

namespace Nilts
{
	namespace Engine
	{
		class Realm;
		
		enum EntityType
		{
			NONE,
			UNDEFINED,
			STANDARD_ENTITY,
			VOXEL_ENTITY,
			TERRAIN_ENTITY,
			PARTICLE,
		};
		
		class Entity
		{
			public:
				uint32 id;
				State state;
				EntityType type;
				Realm* realm = nullptr;
			
				void tick();
		};
	}
}

#endif
