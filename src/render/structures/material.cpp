//----LOCAL----
#include "material.h"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			Material::Material(float shininess, float specular_amount, float specular_cap, uint16 effects)
			{
				this->shininess = shininess;
				this->specular_amount = specular_amount;
				this->specular_cap = specular_cap;
				this->effects = effects;
			}
		}
	}
}
