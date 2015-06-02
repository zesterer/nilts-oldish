//----STANDARD----
#include "string"

//----LOCAL----
#include "window.h"
#include "common/io.h"

//----LIBRARY----
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

using namespace std;

namespace Nilts
{
	namespace Core
	{
		Window::Window()
		{
			IO::output("Creating Window");

			//Start up GLFW
			IO::test(glfwInit(), "Initialising GLFW", true);

			//Create the window
			this->glfw_window = glfwCreateWindow(this->width, this->height, this->window_title.c_str(), NULL, NULL);
			IO::test(this->glfw_window != NULL, "Creating window", true);
		}

		void Window::enable()
		{
			IO::output("Enabling Window");

			glfwMakeContextCurrent(this->glfw_window);
		}

		void Window::close()
		{
			glfwDestroyWindow(this->glfw_window);

			glfwTerminate();

			IO::output("Closed Window");
		}

		bool Window::refresh()
		{
			glfwSwapBuffers(this->glfw_window);

			glfwPollEvents();

			return !glfwWindowShouldClose(this->glfw_window);
		}
	}
}
