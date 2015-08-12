#ifndef NILTS_ENGINE_METADATA_H
#define NILTS_ENGINE_METADATA_H

namespace Nilts
{
	namespace Engine
	{
		class VoxelField;
		class Entity;
		class Realm;
		
		class MetaData
		{
			public:
				Realm* realm;
				
				virtual bool save();
		};
	}
}

#endif
