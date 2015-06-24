#ifndef NILTS_VISUAL_SCENE_H
#define NILTS_VISUAL_SCENE_H

//----STANDARD----
#include "unordered_set"
#include "vector"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "camera.h"
#include "data/object.h"
#include "data/bufferedmesh.h"
#include "data/shader.h"
#include "data/light.h"
#include "data/material.h"
#include "data/framebuffer.h"

using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		class Scene
		{
			public:
				Data::FrameBuffer* default_framebuffer;

				Camera* camera;

				unordered_set<Data::Object*> objects;

				vector<Data::Light> lights;

				Data::Shader* shader;

				Scene();
				void enable();
				void render();
				void renderToFrameBuffer(Data::FrameBuffer* framebuffer);
				void renderFrameBuffer(Data::FrameBuffer* framebuffer);
				void update();

				void assignLights();
				void registerObject(Data::Object* object);
				void deregisterObject(Data::Object* object);
		};
	}
}

#endif // NILTS_VISUAL_SCENE_H
