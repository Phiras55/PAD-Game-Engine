#include <Channel.h>

namespace sl
{
	Channel::Channel() :
		filePath(""),
		chanOutput(ChanOutput::ALL)
	{

	}

	void Channel::WriteLine(const std::string& line)
	{
		WriteLine(line.c_str());
	}

	void Channel::WriteLine(const char* line)
	{
		if (operator&(chanOutput, ChanOutput::FILE) != ChanOutput::NONE)
		{

		}
	}

} // namespace sl