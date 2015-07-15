#ifndef NILTS_RENDER_STRUCTURES_POLYGON_H
#define NILTS_RENDER_STRUCTURES_POLYGON_H

//----LOCAL----
#include "vertex.h"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			struct Polygon
			{
				public:
					Vertex a, b, c;
				
					void correctNormals(float curvature_bias);
					void invert();
			};
		}
	}
}

#endif
