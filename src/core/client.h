#ifndef NILTS_CORE_CLIENT_H
#define NILTS_CORE_CLIENT_H

//----LOCAL----
#include "window.h"

namespace Nilts
{
	namespace Core
	{
		class Client
		{
			public:
				Window* window;

				Client();
				bool run();
		};
	}
}

#endif // NILTS_CORE_CLIENT_H
