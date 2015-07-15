#ifndef NILTS_RENDER_STRUCTURES_LIGHT_H
#define NILTS_RENDER_STRUCTURES_LIGHT_H

namespace Nilts
{
	namespace Render
	{
		namespace Structures
		{
			enum LightType
			{
				DIRECTIONAL,
				POINT
			};

			struct Light
			{
				public: LightType type;
				public: glm::vec3 position;
				public: glm::vec3 colour;
				public: GLfloat ambiance;
			};
		}
	}
}

#endif
