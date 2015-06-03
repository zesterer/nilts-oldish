//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "material.h"

using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			Material::Material(GLfloat shininess, GLfloat specular_amount, GLfloat specular_cap, GLint effects)
			{
				this->shininess = shininess;
				this->specular_amount = specular_amount;
				this->specular_cap = specular_cap;
				this->effects = effects;
			}
		}
	}
}
