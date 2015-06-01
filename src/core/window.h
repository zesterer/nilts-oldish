#ifndef NILTS_CORE_WINDOW_H
#define NILTS_CORE_WINDOW_H

//----STANDARD----
#include "string"

//----LIBRARY----
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

//----LOCAL----
#include "common/types.h"

using namespace std;

namespace Nilts
{
	namespace Core
	{
		class Window
		{
			public: uint16 width = 640 * 1.4;
			public: uint16 height = 480 * 1.4;
			public: string window_title = "Nilts";

			public: GLFWwindow* glfw_window;

			public: Window();
			public: void close();
			public: bool refresh();
			public: void activate();
		};
	}
}

#endif // NILTS_CORE_WINDOW_H
