#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <mutex>

#include <Logger/Channel.h>

#define CPARAMETER "%%"

#ifdef LOGGER
	#define LOG_FLUSH() sl::SimpleLogger::Flush()
	#define LOG_INIT() sl::SimpleLogger::Init()

	#define LOG_INFO(cFormat, ...) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::INFO, cFormat, __VA_ARGS__)
	#define LOG_TRACE(cFormat, ...) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::TRACE, cFormat, __VA_ARGS__)
	#define LOG_WARNING(cFormat, ...) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::WARNING, cFormat, __VA_ARGS__)
	#define LOG_ERROR(cFormat, ...) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::ERROR, cFormat, __VA_ARGS__)
	#define LOG_FATAL(cFormat, ...) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::FATAL, cFormat, __VA_ARGS__)
	#define LOG_CUSTOM(channelType, cFormat, ...) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, channelType, cFormat, __VA_ARGS__)

	#define LOG_INFO_S(cFormat) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::INFO, cFormat, 0)
	#define LOG_TRACE_S(cFormat) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::TRACE, cFormat, 0)
	#define LOG_WARNING_S(cFormat) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::WARNING, cFormat, 0)
	#define LOG_ERROR_S(cFormat) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::ERROR, cFormat, 0)
	#define LOG_FATAL_S(cFormat) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::FATAL, cFormat, 0)
	#define LOG_CUSTOM_S(channelType, cFormat) sl::SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, channelType, cFormat, 0)
#else
	#define LOG_INIT() void(0)
	#define LOG_FLUSH() void(0)

	#define LOG_INFO(cFormat, ...)		void(0)
	#define LOG_TRACE(cFormat, ...)		void(0)
	#define LOG_WARNING(cFormat, ...)	void(0)
	#define LOG_ERROR(cFormat, ...)		void(0)
	#define LOG_FATAL(cFormat, ...)		void(0)
	#define LOG_CUSTOM(channelType, cFormat, ...) void(0)

	#define LOG_INFO_S(cFormat) void(0)
	#define LOG_TRACE_S(cFormat) void(0)
	#define LOG_WARNING_S(cFormat) void(0)
	#define LOG_ERROR_S(cFormat) void(0)
	#define LOG_FATAL_S(cFormat) void(0)
	#define LOG_CUSTOM_S(channelType, cFormat) void(0)
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
	static std::mutex					m_mutex;

public:
	template<typename T, typename... Targs>
	static void Log(
		const char*				_sourceFileName,
		const int				_sourceLine,
		const char*				_date,
		const char*				_time,
		const E_CHANNEL_TYPE	_chan, 
		const std::string&		_format,
		const T&				_arg,
		Targs&&...				_args);

	static void Init();
	static void Flush();
	static void SetChannelOutput(const ChanType _chan, const ChanOutput _output);
	static void SetChannelRestriction(const ChanType _chan, const ChanRestrict _r);

private:
	template<typename T, typename... Targs>
	static void BuildMessage(const std::string& _format, Message& _m, int _findStart, const T& _a, Targs&&... _args);
	static void BuildMessage(const std::string& _format, Message& _m, int _findStart) {}
	static void ShowMessage(const Message& _m);
	static void CloseFiles();

public:
	SimpleLogger& operator=(const SimpleLogger&)	= delete;
	SimpleLogger& operator=(SimpleLogger&&)			= delete;
};

std::string StripPath(const char* path);

} // namespace sl

namespace std
{
	std::string to_string(const std::string& s);
	std::string to_string(const char* s);
}

#include <Logger/SimpleLogger_impl.h>