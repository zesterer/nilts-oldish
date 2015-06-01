//----STANDARD----
#include "string"
#include "iostream"

//----LOCAL----
#include "io.h"
#include "main.h"

using namespace std;

namespace Nilts
{
	namespace IO
	{
		void output(string message, OutputType type)
		{
			string output_strings[] = {"OUTPUT", "DEBUG", "ERROR"};

			if ((NILTS_DEBUG_ENABLED && type == OutputType::DEBUG) || type != OutputType::DEBUG)
			{
				string output_tag = output_strings[type];

				cout << "[" << output_tag << "]: " << message << endl;
			}
		}

		bool test(bool test, string label, bool critical, bool silent)
		{
			if (test)
			{
				if (!silent)
					output(label + ": success", OutputType::DEBUG);
			}
			else
			{
				output(label + ": failure", OutputType::ERROR);

				if (critical)
				{
					output("Critical error, program closing.", OutputType::ERROR);
					exit(EXIT_FAILURE);
				}
			}

			return test;
		}
	}
}
