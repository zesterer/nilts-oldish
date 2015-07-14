#ifndef NILTS_MACRO_SIMULATOR_H
#define NILTS_MACRO_SIMULATOR_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "region.h"

namespace Nilts
{
	namespace Macro
	{
		class Simulator
		{
			public:
				//The world dimensions
				glm::ivec3 size;
				//The world contents
				std::vector<Region> regions;
		};
	}
}

#endif
