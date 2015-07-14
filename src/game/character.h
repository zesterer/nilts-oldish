#ifndef NILTS_GAME_CHARACTER_H
#define NILTS_GAME_CHARACTER_H

//----LOCAL----
#include "actor.h"

namespace Nilts
{
	namespace Game
	{
		class Character : public Actor
		{
			public:
				bool has_ai;
		};
	}
}

#endif
