#include <SimpleLogger.h>

using namespace sl;

SimpleLogger::SimpleLogger()
{

}

SimpleLogger::~SimpleLogger()
{

}

void SimpleLogger::PrintHeaders(const E_CHANNEL_TYPE channels)
{
	if (operator&(channels, E_CHANNEL_TYPE::INFO) != E_CHANNEL_TYPE::NONE)
		std::cout << "[INFO] ";
	if (operator&(channels, E_CHANNEL_TYPE::TRACE) != E_CHANNEL_TYPE::NONE)
		std::cout << "[TRACE] ";
	if (operator&(channels, E_CHANNEL_TYPE::WARNING) != E_CHANNEL_TYPE::NONE)
		std::cout << "[WARNING] ";
	if (operator&(channels, E_CHANNEL_TYPE::ERROR) != E_CHANNEL_TYPE::NONE)
		std::cout << "[ERROR] ";
	if (operator&(channels, E_CHANNEL_TYPE::FATAL) != E_CHANNEL_TYPE::NONE)
		std::cout << "[FATAL] ";
}