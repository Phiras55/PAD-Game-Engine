#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <mutex>

#include <Channel.h>

#define CPARAMETER "%%"

#ifdef LOGGER
	#define LOG_FLUSH() SimpleLogger::Flush()
	#define LOG_INIT() SimpleLogger::Init()

	#define LOG_INFO(cFormat, ...) SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::INFO, cFormat, __VA_ARGS__)
	#define LOG_TRACE(cFormat, ...) SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::TRACE, cFormat, __VA_ARGS__)
	#define LOG_WARNING(cFormat, ...) SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::WARNING, cFormat, __VA_ARGS__)
	#define LOG_ERROR(cFormat, ...) SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::ERROR, cFormat, __VA_ARGS__)
	#define LOG_FATAL(cFormat, ...) SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, E_CHANNEL_TYPE::FATAL, cFormat, __VA_ARGS__)
	#define LOG_CUSTOM(channelType, cFormat, ...) SimpleLogger::Log(__FILE__, __LINE__, __DATE__, __TIME__, channelType, cFormat, __VA_ARGS__)
#else
	#define LOG_INIT() void(0)
	#define LOG_FLUSH() void(0)

	#define LOG_INFO(cFormat, ...) void(0)
	#define LOG_TRACE(cFormat, ...) void(0)
	#define LOG_WARNING(cFormat, ...) void(0)
	#define LOG_ERROR(cFormat, ...) void(0)
	#define LOG_FATAL(cFormat, ...) void(0)
	#define LOG_CUSTOM(channelType, cFormat, ...) void(0)
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
	static LOGGER_API void Log(
		const char*				_sourceFileName,
		const int				_sourceLine,
		const char*				_date,
		const char*				_time,
		const E_CHANNEL_TYPE	_chan, 
		const std::string&		_format,
		const T&				_arg,
		Targs&&...				_args);

	static LOGGER_API void Init();
	static LOGGER_API void Flush();
	static LOGGER_API void SetChannelOutput(const ChanType _chan, const ChanOutput _output);
	static LOGGER_API void SetChannelRestriction(const ChanType _chan, const ChanRestrict _r);

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

} // namespace sl

#include <SimpleLogger_impl.h>