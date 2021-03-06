//----LIBRARY----
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

//----LOCAL----
#include "camera.h"

namespace Nilts
{
	namespace Engine
	{
		Camera::Camera(Realm* realm)
		{
			this->position = glm::vec3(-4.0, 0.0, 00.0);
			this->rotation = glm::vec3(0.0, 0.6, 0.0);
			
			this->realm = realm;
		}
		
		void Camera::update()
		{
			//Clear the matrix ready for updating
			this->matrix = glm::mat4(1.0);

			//Apply the new transformations to it
			this->matrix = glm::rotate(this->matrix, this->rotation.z, glm::vec3(0.0, 0.0, 1.0)); //Roll
			this->matrix = glm::rotate(this->matrix, this->rotation.y - (float)M_PI / 2.0f, glm::vec3(1.0, 0.0, 0.0)); //Pitch
			this->matrix = glm::rotate(this->matrix, this->rotation.x, glm::vec3(0.0, 0.0, 1.0)); //Yaw
			//The position
			this->matrix = glm::translate(this->matrix, glm::vec3(-this->position.x, -this->position.y, -this->position.z));
			//Perspective / projection
			this->perspective_matrix = glm::perspective(this->fov, 640.0f / 480.0f, this->min_render, this->max_render);
		}
		
		void Camera::keys(Core::Window* window)
		{
			///*Testing - Check keyboard
			if (glfwGetKey(window->glfw_window, GLFW_KEY_D) == GLFW_PRESS)
			{
				this->position.x += 0.15 * sin(this->rotation.x + M_PI / 2);
				this->position.y += 0.15 * cos(this->rotation.x + M_PI / 2);
			}
			if (glfwGetKey(window->glfw_window, GLFW_KEY_A) == GLFW_PRESS)
			{
				this->position.x += 0.15 * sin(this->rotation.x - M_PI / 2);
				this->position.y += 0.15 * cos(this->rotation.x - M_PI / 2);
			}
			if (glfwGetKey(window->glfw_window, GLFW_KEY_W) == GLFW_PRESS)
			{
				this->position.x += 0.15 * sin(this->rotation.x);
				this->position.y += 0.15 * cos(this->rotation.x);
			}
			if (glfwGetKey(window->glfw_window, GLFW_KEY_S) == GLFW_PRESS)
			{
				this->position.x += 0.15 * sin(this->rotation.x + M_PI);
				this->position.y += 0.15 * cos(this->rotation.x + M_PI);
			}
			if (glfwGetKey(window->glfw_window, GLFW_KEY_M) == GLFW_PRESS)
				this->position.z += 0.15;
			if (glfwGetKey(window->glfw_window, GLFW_KEY_N) == GLFW_PRESS)
				this->position.z -= 0.15;
			if (glfwGetKey(window->glfw_window, GLFW_KEY_P) == GLFW_PRESS)
				this->position.z += 15.0;
			if (glfwGetKey(window->glfw_window, GLFW_KEY_O) == GLFW_PRESS)
				this->position.z -= 15.0;

			if (glfwGetKey(window->glfw_window, GLFW_KEY_RIGHT) == GLFW_PRESS)
				this->rotation.x += 0.03;
			if (glfwGetKey(window->glfw_window, GLFW_KEY_LEFT) == GLFW_PRESS)
				this->rotation.x -= 0.03;
			if (glfwGetKey(window->glfw_window, GLFW_KEY_UP) == GLFW_PRESS)
				this->rotation.y += 0.03;
			if (glfwGetKey(window->glfw_window, GLFW_KEY_DOWN) == GLFW_PRESS)
				this->rotation.y -= 0.03;
			if (glfwGetKey(window->glfw_window, GLFW_KEY_J) == GLFW_PRESS)
				this->rotation.z -= 0.03;
			if (glfwGetKey(window->glfw_window, GLFW_KEY_L) == GLFW_PRESS)
				this->rotation.z += 0.03;
			//*/
		}
	}
}
