#ifndef NILTS_WORLD_WORLD_H
#define NILTS_WORLD_WORLD_H

//----STANDARD----
#include "string"

//----LOCAL----
#include "terrain/terrain.h"

using namespace std;

namespace Nilts
{
	namespace World
	{
		class World
		{
			public:
				Terrain::Terrain* terrain;
		};
	}
}

#endif // NILTS_WORLD_WORLD_H
