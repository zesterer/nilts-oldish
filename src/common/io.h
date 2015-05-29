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

		void output(string message, OutputType type = OutputType::DEBUG)
		{
			if ((DEBUG_ENABLED && type == OutputType::DEBUG) || type != OutputType::DEBUG)
			{
				string output_tag;

				switch(type)
				{
					case (OutputType::INFO) :
						output_tag = "OUTPUT";
						break;
					case (OutputType::DEBUG) :
						output_tag = "DEBUG";
						break;
					case (OutputType::ERROR) :
						output_tag = "ERROR";
						break;
				}

				cout << "[" << output_tag << "]: " << message << endl;
			}
		}
	}
}

#endif // NILTS_COMMON_IO_H
