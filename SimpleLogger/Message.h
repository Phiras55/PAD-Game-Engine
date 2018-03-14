#pragma once
#include <SimpleLoggerEnums.h>

namespace sl
{

struct Message
{
	Message(const char* _sourceFileName, const char* _time, const char* _date, const int _sourceLine, const E_CHANNEL_TYPE _channels) :
		sourceFileName(_sourceFileName),
		time(_time),
		date(_date),
		sourceLine(_sourceLine),
		channels(_channels)
	{

	}

	const char*			 sourceFileName;
	const char*			 time;
	const char*			 date;
	const int			 sourceLine;
	const E_CHANNEL_TYPE channels;
};

} // namespace sl