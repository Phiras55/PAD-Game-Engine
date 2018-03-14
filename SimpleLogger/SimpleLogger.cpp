#include <SimpleLogger.h>

using namespace sl;

std::queue<Message>			SimpleLogger::m_messages;
std::map<ChanType, Channel> SimpleLogger::m_channels;

SimpleLogger::SimpleLogger()
{

}

SimpleLogger::~SimpleLogger()
{

}

void SimpleLogger::Init()
{
	m_channels[E_CHANNEL_TYPE::INFO] = Channel();
}

void SimpleLogger::PrintHeaders(const E_CHANNEL_TYPE channels)
{
	/*if (operator&(channels, E_CHANNEL_TYPE::INFO) != E_CHANNEL_TYPE::NONE)
		std::cout << "[INFO] ";
	if (operator&(channels, E_CHANNEL_TYPE::TRACE) != E_CHANNEL_TYPE::NONE)
		std::cout << "[TRACE] ";
	if (operator&(channels, E_CHANNEL_TYPE::WARNING) != E_CHANNEL_TYPE::NONE)
		std::cout << "[WARNING] ";
	if (operator&(channels, E_CHANNEL_TYPE::ERROR) != E_CHANNEL_TYPE::NONE)
		std::cout << "[ERROR] ";
	if (operator&(channels, E_CHANNEL_TYPE::FATAL) != E_CHANNEL_TYPE::NONE)
		std::cout << "[FATAL] ";*/
}