#ifndef NILTS_COMMON_TYPES_H
#define NILTS_COMMON_TYPES_H

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
		int32 x, y, z;
	};

	struct FloatPos
	{
		float64 x, y, z;
	};
}

#endif // NILTS_COMMON_TYPES_H
