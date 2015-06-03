#ifndef NILTS_COMMON_TYPES_H
#define NILTS_COMMON_TYPES_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Nilts
{
	/*
	Of course the real size of each
	data type will vary from system
	to system, but they still have
	to have the same standardised
	limits at minimum.
	*/

	//Integer types
	typedef char int8;
	typedef unsigned char uint8;

	typedef short int16;
	typedef unsigned short uint16;

	typedef long int32;
	typedef unsigned long uint32;

	//Floating-point types
	typedef float float32;
	typedef double float64;

	struct IntPos
	{
		int32 x = 0;
		int32 y = 0;
		int32 z = 0;
	};

	struct FloatPos
	{
		float64 x = 0.0;
		float64 y = 0.0;
		float64 z = 0.0;
	};

	struct Rotation
	{
		float32 x = 0.0;
		float32 y = 0.0;
		float32 z = 0.0;
	};

	struct Scale
	{
		float32 x = 1.0;
		float32 y = 1.0;
		float32 z = 1.0;
	};

	struct State
	{
		glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
		glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);
		glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
	};

	struct Matrix
	{
		glm::mat4x4 matrix;

		void updateFrom(State state);
	};
}

#endif // NILTS_COMMON_TYPES_H
