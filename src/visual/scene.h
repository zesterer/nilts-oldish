#ifndef NILTS_VISUAL_SCENE_H
#define NILTS_VISUAL_SCENE_H

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "camera.h"

namespace Nilts
{
	namespace Visual
	{
		class Scene
		{
			public:
				Camera* camera;

				Scene();
				void enable();
				void render();
		};
	}
}

#endif // NILTS_VISUAL_SCENE_H
