#ifndef NILTS_RENDER_RENDERABLE_H
#define NILTS_RENDER_RENDERABLE_H

//----LOCAL----
#include "common/types.h"

namespace Nilts
{
	namespace Render
	{
		enum RenderType
		{
			MESH,
			BILLBOARD,
		};
		
		class Renderable
		{
			public:
				RenderType render_type;
		};
	}
}

#endif
