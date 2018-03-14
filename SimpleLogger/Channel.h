#pragma once
#include <string>
#include <fstream>
#include <SimpleLoggerEnums.h>

namespace sl {

struct Channel
{
	Channel();
	~Channel() = default;

	std::string			filePath;
	std::ofstream		file;
	E_CHANNEL_OUTPUT	chanOutput;

	void WriteLine(const std::string& line);
	void WriteLine(const char* line);
};

} // namespace sl