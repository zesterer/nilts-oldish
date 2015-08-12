#ifndef NILTS_ENGINE_REALM_H
#define NILTS_ENGINE_REALM_H

//----STANDARD----
#include "set"

//----LOCAL----
#include "voxelterrain.h"
#include "entity.h"
#include "camera.h"

namespace Nilts
{
	namespace Engine
	{
		class Realm
		{
			public:
				Camera* camera;
				
				VoxelTerrain* terrain;
				std::set<Entity*> entities;
				
				uint64 time;
				
				Realm();
				void tick();
				void registerEntity(Entity* entity);
				void deregisterEntity(Entity* entity);
		};
	}
}

#endif
