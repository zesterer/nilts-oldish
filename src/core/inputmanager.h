#ifndef NILTS_CORE_INPUTMANAGER_H
#define NILTS_CORE_INPUTMANAGER_H

//----LIBRARY----
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace Nilts
{
	namespace Core
	{
		class InputManager
		{
			public:
				bool key_w = false;
				bool key_a = false;
				bool key_s = false;
				bool key_d = false;
			
				bool key_up = false;
				bool key_left = false;
				bool key_down = false;
				bool key_right = false;
				
				bool key_space = false;
				bool key_enter = false;
				bool key_lshift = false;
				bool key_lcontrol = false;
				
				void tick(GLFWwindow* window);
		};
	}
}

#endif
