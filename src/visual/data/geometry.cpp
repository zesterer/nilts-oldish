//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

//----LOCAL----
#include "geometry.h"

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			void Polygon::correctNormals()
			{
				glm::vec3 n0 = glm::cross(this->b.pos - this->a.pos, this->c.pos - this->a.pos);
				n0 /= glm::length(n0);

				this->a.norm = n0;
				this->b.norm = n0;
				this->c.norm = n0;
			}
		}
	}
}
