//----LOCAL----
#include "realm.h"
#include "common/io.h"

namespace Nilts
{
	namespace Engine
	{
		Realm::Realm()
		{
			this->camera = new Camera(this);
			
			this->terrain = new VoxelTerrain(glm::ivec3(32, 32, 32));
		}
		
		void Realm::tick()
		{
			this->camera->update();
			
			this->time ++;
		}
		
		void Realm::registerEntity(Entity* entity)
		{
			this->entities.insert(entity);
			entity->realm = this;
		}
		
		void Realm::deregisterEntity(Entity* entity)
		{
			this->entities.erase(entity);
			entity->realm = nullptr;
		}
	}
}
