//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

//----LOCAL----
#include "types.h"

namespace Nilts
{
	void State::tick()
	{
		this->pos += this->velocity;
		this->rot += this->spin;
	}
	
	void State::update()
	{
		//Clear the matrix ready to change it
		this->matrix = glm::mat4(1.0f);

		//Apply entity transformations
		this->matrix = glm::translate(this->matrix, this->pos);
		this->matrix = glm::rotate(this->matrix, this->rot.x, glm::vec3(0.0, 0.0, 1.0)); //Yaw
		this->matrix = glm::rotate(this->matrix, this->rot.y, glm::vec3(1.0, 0.0, 0.0)); //Pitch
		this->matrix = glm::rotate(this->matrix, this->rot.z, glm::vec3(0.0, 0.0, 1.0)); //Roll
		this->matrix = glm::scale(this->matrix, this->scale);
	}
	
	int32 IntVec3::sum()
	{
		return this->x * this->y * this->z;
	}

	void Matrix::updateFrom(State state)
	{
		//Clear the matrix ready to change it
		this->matrix = glm::mat4(1.0f);

		//Apply entity transformations
		this->matrix = glm::translate(this->matrix, state.pos);
		this->matrix = glm::rotate(this->matrix, state.rot.x, glm::vec3(0.0, 0.0, 1.0)); //Yaw
		this->matrix = glm::rotate(this->matrix, state.rot.y, glm::vec3(1.0, 0.0, 0.0)); //Pitch
		this->matrix = glm::rotate(this->matrix, state.rot.z, glm::vec3(0.0, 0.0, 1.0)); //Roll
		this->matrix = glm::scale(this->matrix, state.scale);
	}
}
