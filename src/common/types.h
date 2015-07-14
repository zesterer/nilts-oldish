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
	
	typedef long long int64;
	typedef unsigned long long uint64;

	//Floating-point types
	typedef float float32;
	typedef double float64;

	struct IntVec2
	{
		int32 x, y;
	};

	struct IntVec3
	{
		int32 x, y, z;

		int32 sum();
	};

	struct IntVec4
	{
		int32 x, y, z, w;
	};

	struct IntPos
	{
		int32 x = 0;
		int32 y = 0;
		int32 z = 0;

		bool operator==(const IntPos &pos) const
		{
			if (pos.x == this->x && pos.y == this->y && pos.z == this->z)
				return true;
			return false;
		}
	};

	struct State
	{
		public:
			//The combined matrix
			glm::mat4x4 matrix;
			//The static state components
			glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
			glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);
			glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
			//The motion state components
			glm::vec3 velocity = glm::vec3(0.0, 0.0, 0.0);
			glm::vec3 spin = glm::vec3(0.0, 0.0, 0.0);
			//The physical state components
			float mass = 0.0;
			glm::vec3 comass = glm::vec3(0.0, 0.0, 0.0);
		
			void tick();
	};

	struct Matrix
	{
		glm::mat4x4 matrix;

		void updateFrom(State state);
	};
}

#endif // NILTS_COMMON_TYPES_H
