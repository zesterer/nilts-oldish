//----STANDARD----
#include "string"

//----LOCAL----
#include "manager.h"
#include "common/io.h"
#include "engine/voxelterrain.h"

namespace Nilts
{
	namespace Game
	{
		Manager::Manager(Core::InputManager* inputmanager)
		{
			//Just assign the input manager
			this->inputmanager = inputmanager;
			
			//Create the realm
			this->realm = new Engine::Realm();
			this->realm->terrain = new Engine::VoxelTerrain(glm::ivec3(32, 32, 32));
			this->realm->terrain->loadAt(glm::ivec3(0, 0, 0));
		}
		
		void Manager::tick()
		{
			this->time ++;
			
			//Tick the realm
			this->realm->tick();
			
			//IO::output("The time is " + std::to_string(this->time));
			
			if (this->inputmanager->key_up)
				IO::output("Up is pressed!");
			if (this->inputmanager->key_left)
				IO::output("Left is pressed!");
			if (this->inputmanager->key_down)
				IO::output("Down is pressed!");
			if (this->inputmanager->key_right)
				IO::output("Right is pressed!");
		}
	}
}
