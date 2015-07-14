//----LOCAL----
#include "realm.h"
#include "common/io.h"

namespace Nilts
{
	namespace Engine
	{
		void Realm::tick()
		{
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
