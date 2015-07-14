#ifndef NILTS_CORE_WINDOW_H
#define NILTS_CORE_WINDOW_H

//----STANDARD----
#include "string"

//----LIBRARY----
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

//----LOCAL----
#include "common/types.h"
#include "inputmanager.h"

using namespace std;

namespace Nilts
{
	namespace Core
	{
		class Window
		{
			public:
				uint16 width = 640 * 1.4;
				uint16 height = 480 * 1.4;
				string window_title = "Nilts";

				GLFWwindow* glfw_window;
				
				InputManager* inputmanager;

				Window(InputManager* inputmanager);
				void close();
				bool refresh();
				void enable();
		};
	}
}

#endif // NILTS_CORE_WINDOW_H
