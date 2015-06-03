//----LOCAL----
#include "object.h"

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			Object::Object()
			{
				this->mesh = new Data::BufferedMesh();
				this->material = new Data::Material(15.0, 0.6, 2.0, 0b10);
			}

			void Object::update()
			{
				this->matrix.updateFrom(this->state);
			}
		}
	}
}
