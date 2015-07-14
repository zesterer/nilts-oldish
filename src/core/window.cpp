//----STANDARD----
#include "string"

//----LOCAL----
#include "window.h"
#include "common/io.h"

//----LIBRARY----
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

using namespace std;

namespace Nilts
{
	namespace Core
	{
		Window::Window(InputManager* inputmanager)
		{
			IO::output("Creating Window");
			
			this->inputmanager = inputmanager;

			//Start up GLFW
			IO::test(glfwInit(), "Initialising GLFW", true);

			//Tell the program to make an OpenGL 3.0 compatible context
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
			//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, (int)gl::GL_TRUE);

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
			
			this->inputmanager->tick(this->glfw_window);

			return !glfwWindowShouldClose(this->glfw_window);
		}
	}
}
