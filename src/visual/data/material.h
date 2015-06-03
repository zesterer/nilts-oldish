#ifndef NILTS_VISUAL_DATA_MATERIAL_H
#define NILTS_VISUAL_DATA_MATERIAL_H

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			struct Material
			{
				public:
					GLfloat shininess;
					GLfloat specular_amount;
					GLfloat specular_cap;
					GLint effects;

					Material(GLfloat shininess = 15.0, GLfloat specular_amount = 0.6, GLfloat specular_cap = 2.0, GLint effects = 0b10);
			};
		}
	}
}

#endif // NILTS_VISUAL_DATA_MATERIAL_H
