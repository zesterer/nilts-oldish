//----LOCAL----
#include "polygon.h"

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			void Polygon::correctNormals(float curvature_bias)
			{
				glm::vec3 n0 = glm::cross(this->b.pos - this->a.pos, this->c.pos - this->a.pos);
				n0 /= glm::length(n0);

				glm::vec3 average = (this->a.pos + this->b.pos + this->c.pos) / glm::vec3(3.0, 3.0, 3.0);

				this->a.norm = n0 + (a.norm - average) * curvature_bias;
				this->b.norm = n0 + (b.norm - average) * curvature_bias;
				this->c.norm = n0 + (c.norm - average) * curvature_bias;
			}

			void Polygon::invert()
			{
				//Swap the vertices around
				Vertex temp = this->a;
				this->a = this->c;
				this->c = temp;

				//Recalculate the normals
				this->correctNormals();
			}
		}
	}
}
