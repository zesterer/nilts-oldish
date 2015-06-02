#ifndef NILTS_VISUAL_SCENE_H
#define NILTS_VISUAL_SCENE_H

//----STANDARD----
#include "unordered_set"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "camera.h"
#include "data/object.h"

using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		class Scene
		{
			public:
				Camera* camera;

				unordered_set<Data::Object*> active_objects;

				Scene();
				void enable();
				void render();

				void registerObject(Data::Object* object);
				void deregisterObject(Data::Object* object);
		};
	}
}

#endif // NILTS_VISUAL_SCENE_H
