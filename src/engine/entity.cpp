//----LOCAL----
#include "entity.h"

namespace Nilts
{
	namespace Engine
	{
		void Entity::tick()
		{
			this->state.tick();
		}
	}
}
