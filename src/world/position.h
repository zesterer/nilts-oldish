#ifndef NILTS_WORLD_POSITION_H
#define NILTS_WORLD_POSITION_H

//----STANDARD----

using namespace std;

namespace Nilts
{
	namespace World
	{
		struct VoxelPos
		{
			public:
				long x, y, z;
		};

		struct EntityPos
		{
			public:
				double x, y, z;
		};
	}
}

#endif // NILTS_WORLD_POSITION_H
