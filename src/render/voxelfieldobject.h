#ifndef NILTS_RENDER_VOXELFIELDOBJECT_H
#define NILTS_RENDER_VOXELFIELDOBJECT_H

//----LOCAL----
#include "meshobject.h"
#include "engine/metadata.h"
#include "engine/voxelfield.h"
#include "engine/realm.h"
#include "common/types.h"
#include "structures/framebuffer.h"

namespace Nilts
{
	namespace Render
	{
		class VoxelFieldObject : public MeshObject, public Engine::MetaData
		{
			public:
				Engine::VoxelField* parent;
				
				VoxelFieldObject(Engine::Realm* realm, Engine::VoxelField* parent);
				
				virtual void render(State* state, Structures::FrameBuffer* framebuffer);
		};
	}
}

#endif
