#ifndef NILTS_GAME_ACTOR_H
#define NILTS_GAME_ACTOR_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "engine/entity.h"

namespace Nilts
{
	namespace Game
	{
		class Actor
		{
			public:
				std::vector<int> properties;
				Engine::Entity* entity;
		};
	}
}

#endif
