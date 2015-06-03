#ifndef NILTS_VISUAL_DATA_OBJECT_H
#define NILTS_VISUAL_DATA_OBJECT_H

//----LOCAL----
#include "geometry.h"
#include "common/types.h"
#include "bufferedmesh.h"
#include "material.h"

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			class Object
			{
				public:
					State state;
					Matrix matrix;

					BufferedMesh* mesh;
					Material* material;

					Object();
					void update();
			};
		}
	}
}

#endif // NILTS_VISUAL_DATA_OBJECT_H
