//----STANDARD----
#include "string"

//----LOCAL----
#include "main.h"
#include "common/io.h"
#include "common/args.h"
#include "core/application.h"

using namespace std;

namespace Nilts
{
	int main(int argc, char* argv[])
	{
		//Create the initial program configuration
		Core::AppConfig* config = new Core::AppConfig();

		//Read the arguments
		checkArguments(config, argc, argv);

		//Create the application with the specified config
		Core::Application* application;
		application = new Core::Application(config);

		return application->run();
	}

	char* getVersionArray()
	{
		static char version[3];
		version[0] = NILTS_VERSION_MAJOR;
		version[1] = NILTS_VERSION_MINOR;
		version[2] = NILTS_VERSION_RELEASE;
		return version;
	}

	string getVersionString()
	{
		return to_string(NILTS_VERSION_MAJOR) + "." + to_string(NILTS_VERSION_MINOR) + "." + to_string(NILTS_VERSION_RELEASE);
	}
}

int main(int argc, char* argv[])
{
	return Nilts::main(argc, argv);
}
