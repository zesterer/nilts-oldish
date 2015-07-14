//----LOCAL----
#include "inputmanager.h"

namespace Nilts
{
	namespace Core
	{
		void InputManager::tick(GLFWwindow* window)
		{
			this->key_w = (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS);
			this->key_a = (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS);
			this->key_s = (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS);
			this->key_d = (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS);
			
			this->key_up = (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS);
			this->key_left = (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS);
			this->key_down = (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS);
			this->key_right = (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS);
			
			this->key_space = (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS);
			this->key_enter = (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS);
			this->key_lshift = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS);
			this->key_lcontrol = (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS);
		}
	}
}
