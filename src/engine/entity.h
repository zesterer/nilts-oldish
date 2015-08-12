#ifndef NILTS_ENGINE_ENTITY_H
#define NILTS_ENGINE_ENTITY_H

//----LOCAL----
#include "common/types.h"
#include "metadata.h"

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
				State state;
				EntityType type;
				Realm* realm = nullptr;
				
				//Entity metadata. Could contain things like
				//AI state data, or inventory data.
				MetaData* render_metadata = nullptr;
				MetaData* game_metadata = nullptr;
			
				void tick();
		};
	}
}

#endif
