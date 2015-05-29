#ifndef NILTS_COMMON_ARGS_H
#define NILTS_COMMON_ARGS_H

//----STANDARD----
#include "string"

//----LOCAL----
#include "core/application.h"
#include "common/io.h"

using namespace std;

namespace Nilts
{
	void checkArguments(Core::AppConfig* config, int argc, char* argv[])
	{
		for (int count = 0; count < argc; count ++)
		{
			if (string(argv[count]) == "-s")
			{
				config->server_not_client = true;
				IO::output("Running in server mode.");
			}
		}
	}
}

#endif // NILTS_COMMON_ARGS_H
