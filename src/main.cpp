//----STANDARD----
#include "string"
#include "iostream"

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

		IO::output("Hello, World! " + getVersionString());

		//Create the application with the specified config
		Core::Application* application;
		application = new Core::Application(config);

		return application->run();
	}
}

int main(int argc, char* argv[])
{
	return Nilts::main(argc, argv);
}
