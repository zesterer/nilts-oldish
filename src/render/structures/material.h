#ifndef NILTS_RENDER_STRUCTURES_MATERIAL_H
#define NILTS_RENDER_STRUCTURES_MATERIAL_H

//----LOCAL----
#include "common/types.h"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			struct Material
			{
				public:
					float shininess;
					float specular_amount;
					float specular_cap;
					uint16 effects;

					Material(float shininess = 15.0, float specular_amount = 0.6, float specular_cap = 2.0, uint16 effects = 0b10);
			};
		}
	}
}

#endif
