#pragma once
#include <Logger/SimpleLoggerEnums.h>

namespace sl
{

struct Message
{
	Message(const E_CHANNEL_TYPE _channels, const std::string& _sourceFileName, const char* _time, const char* _date, const int _sourceLineNumber) :
		sourceFileName(_sourceFileName),
		time(_time),
		date(_date),
		sourceLineNumber(_sourceLineNumber),
		channels(_channels)
	{

	}

	std::string				data;
	std::string				sourceFileName;
	const char*				time;
	const char*				date;
	const int				sourceLineNumber;
	const E_CHANNEL_TYPE	channels;
};

} // namespace sl