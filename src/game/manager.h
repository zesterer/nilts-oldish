#ifndef NILTS_GAME_GAMEMANAGER_H
#define NILTS_GAME_GAMEMANAGER_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "engine/realm.h"
#include "macro/simulator.h"
#include "actor.h"
#include "core/inputmanager.h"
#include "common/types.h"
#include "render/scene.h"

namespace Nilts
{
	namespace Game
	{
		class Manager
		{
			public:
				Engine::Realm* realm;
				Render::Scene* scene;
				
				Macro::Simulator* simulator;
				std::vector<Actor*> actors;
				Core::InputManager* inputmanager;
				
				uint64 time;
				
				Manager(Core::InputManager* inputmanager);
				void tick();
		};
	}
}

#endif
