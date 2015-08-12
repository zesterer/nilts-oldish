#ifndef NILTS_RENDER_MESHOBJECT_H
#define NILTS_RENDER_MESHOBJECT_H

//----LOCAL----
#include "structures/mesh.h"
#include "structures/material.h"
#include "renderable.h"
#include "structures/shader.h"
#include "common/types.h"

namespace Nilts
{
	namespace Render
	{
		class MeshObject : public Renderable
		{
			public:
				State* state;
				Structures::Mesh mesh;
				Structures::Material* material;
				Structures::Shader* shader;
		};
	}
}

#endif
