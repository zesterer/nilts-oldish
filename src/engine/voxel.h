#ifndef NILTS_ENGINE_VOXEL_H
#define NILTS_ENGINE_VOXEL_H

//----LOCAL----
#include "common/types.h"

namespace Nilts
{
	namespace Engine
	{
		struct Voxel
		{
			public:
				//The density of the voxel space (0-255)
				uint8 density;
				//The type of voxel
				uint16 type;
				//8 bits used to contain any extra data
				uint8 data;
		};
	}
}

#endif
