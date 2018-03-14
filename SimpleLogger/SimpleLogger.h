#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <map>

#include <Channel.h>
#include <Message.h>

#define LOGGER

#ifdef LOGGER
	#define LOG_INIT() SimpleLogger::Init()
	#define LOG_INFO(cFormat, ...) SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::INFO, cFormat, __VA_ARGS__)
#else
	#define LOG_INIT() void(0)
	#define LOG_INFO(cFormat, ...) void(0)
#endif


namespace sl {

class SimpleLogger final
{
private:
	SimpleLogger();
	~SimpleLogger();

	SimpleLogger(const SimpleLogger&)	= delete;
	SimpleLogger(SimpleLogger&&)		= delete;

private:
	static std::queue<Message>			m_messages;
	static std::map<ChanType, Channel>	m_channels;

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

	static void Init();

private:
	static void LogRecurs();
	static void PrintHeaders(const E_CHANNEL_TYPE channels);

public:
	SimpleLogger & operator=(const SimpleLogger&)	= delete;
	SimpleLogger& operator=(SimpleLogger&&)			= delete;
};

} // namespace sl

#include <SimpleLogger_impl.h>