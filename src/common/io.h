#ifndef NILTS_COMMON_IO_H
#define NILTS_COMMON_IO_H

//----STANDARD----
#include "string"
#include "main.h"

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
	}
}

#endif // NILTS_COMMON_IO_H
