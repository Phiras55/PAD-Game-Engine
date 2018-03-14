#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <queue>

#include <Channel.h>
#include <SimpleLoggerEnums.h>

#define LOGGER

#ifdef LOGGER
	#define LOG_INFO(cFormat, ...) SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::INFO, cFormat, __VA_ARGS__)
#else
	#define LOG_INFO(cFormat, ...) void(0)
#endif


namespace sl {

using Message		= std::string;

class SimpleLogger final
{
private:
	SimpleLogger();
	~SimpleLogger();

	SimpleLogger(const SimpleLogger&)	= delete;
	SimpleLogger(SimpleLogger&&)		= delete;

private:
	std::queue<Message> m_messages;

public:
	template<typename T, typename... Targs>
	static void Log(
		const char* _sourceFileName,
		const int _sourceLine,
		const char* _date,
		const char* _time,
		const E_CHANNEL_TYPE _chan, 
		const std::string& _format,
		const T& _arg,
		Targs&&... _args);

private:
	static void LogRecurs();
	static void PrintHeaders(const E_CHANNEL_TYPE channels);

public:
	SimpleLogger & operator=(const SimpleLogger&)	= delete;
	SimpleLogger& operator=(SimpleLogger&&)			= delete;
};

} // namespace sl

#include <SimpleLogger_impl.h>