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

		void output(string message, OutputType type = OutputType::DEBUG);

		bool test(bool test, string label = "NULL Test", bool critical = false, bool silent = false);
	}
}

#endif // NILTS_COMMON_IO_H
