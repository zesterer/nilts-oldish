#ifndef NILTS_COMMON_IO_H
#define NILTS_COMMON_IO_H

//----STANDARD----
#include "string"
#include "iostream"

//----LOCAL----
#include "main.h"

using namespace std;

namespace Nilts
{
	namespace IO
	{
		enum OutputType
		{
			INFO,
			DEBUG,
			ERROR
		};

		string output_strings[] = {"OUTPUT", "DEBUG", "ERROR"};

		void output(string message, OutputType type = OutputType::DEBUG)
		{
			if ((DEBUG_ENABLED && type == OutputType::DEBUG) || type != OutputType::DEBUG)
			{
				string output_tag = output_strings[type];

				cout << "[" << output_tag << "]: " << message << endl;
			}
		}

		bool test(bool test, string label = "NULL Test", bool critical = false, bool silent = false)
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

#endif // NILTS_COMMON_IO_H
