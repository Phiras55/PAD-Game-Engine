#pragma once
#include <string>
#include <fstream>

#include <SimpleLoggerEnums.h>
#include <Message.h>

namespace sl {

struct Channel
{
	Channel();
	Channel(const std::string& path, const std::string& name);
	~Channel();

	std::string		filePath;
	std::string		fileName;
	std::ofstream	file;
	ChanOutput		chanOutput;
	ChanRestrict	chanRestrict;

	void WriteLine(const Message& _m);
	void CloseFile();
};

} // namespace sl