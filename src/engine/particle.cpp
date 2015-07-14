//----LOCAL----
#include "particle.h"

namespace Nilts
{
	namespace Engine
	{
		void Particle::tick()
		{
			((Entity*)this)->tick();
			
			if (lifetime > 0)
				this->lifetime --;
		}
	}
}
