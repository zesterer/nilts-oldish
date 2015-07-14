#ifndef NILTS_ENGINE_PARTICLE_H
#define NILTS_ENGINE_PARTICLE_H

//----LOCAL----
#include "entity.h"
#include "common/types.h"

namespace Nilts
{
	namespace Engine
	{
		class Particle : public Entity
		{
			public:
				uint32 lifetime;
			
				void tick();
		};
	}
}

#endif
