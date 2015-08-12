#ifndef NILTS_RENDER_RENDER_H
#define NILTS_RENDER_RENDER_H

//----LOCAL----
#include "meshobject.h"

namespace Nilts
{
	namespace Render
	{
		class Scene;
		
		enum RenderMode
		{
			MESHOBJECT,
		};
		
		class Renderer
		{
			public:
				RenderMode mode = RenderMode::MESHOBJECT;
				Scene* scene;
				
				void renderMeshObject(MeshObject* object);
				
				void setModeMesh();
		};
	}
}

#endif
