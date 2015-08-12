#ifndef NILTS_RENDER_SCENEMANAGER_H
#define NILTS_RENDER_SCENEMANAGER_H

//----LOCAL----
#include "engine/realm.h"
#include "structures/framebuffer.h"
#include "renderer.h"

namespace Nilts
{
	namespace Render
	{
		class Scene
		{
			public:
				Structures::FrameBuffer* render_buffer;
				Engine::Realm* realm;
				
				Renderer renderer;
				
				Scene(Engine::Realm* realm);
				void enable();
				void tick();
				void preRenderSetup();
				void render();
		};
	}
}

#endif
