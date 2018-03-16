#include <iostream>

#include <Logger/Channel.h>

namespace sl
{
	Channel::Channel() :
		filePath(""),
		chanOutput(ChanOutput::ALL),
		chanRestrict(ChanRestrict::ALL)
	{

	}

	Channel::Channel(const std::string& _path, const std::string& _name) :
		filePath(_path), 
		fileName(_name),
		chanOutput(ChanOutput::ALL),
		chanRestrict(ChanRestrict::ALL)
	{

	}

	Channel::~Channel()
	{
		CloseFile();
	}

	void Channel::WriteLine(const Message& _m)
	{
		if (operator&(chanOutput, ChanOutput::FILE) != ChanOutput::NONE)
		{
			if (!file.is_open())
			{
				file.open(filePath + "/" + fileName, std::ios::trunc | std::ios::out);
				if (!file.is_open())
				{
					std::cout << "Error trying to log in file: " << fileName << " at: " << filePath << "\n";
					return;
				}
			}

			if (operator&(chanRestrict, ChanRestrict::DATE) != ChanRestrict::NONE)
				file << "[" << _m.date << "]";
			if (operator&(chanRestrict, ChanRestrict::TIME) != ChanRestrict::NONE)
				file << "[" << _m.time << "]";
			if (operator&(chanRestrict, ChanRestrict::FILENAME) != ChanRestrict::NONE)
				file << "[" << _m.sourceFileName << "]";
			if (operator&(chanRestrict, ChanRestrict::FILELINE) != ChanRestrict::NONE)
				file << "[Line: " << _m.sourceLineNumber << "]";

			file << _m.data;
		}

		if (operator&(chanOutput, ChanOutput::CONSOLE) != ChanOutput::NONE)
		{
			if (operator&(chanRestrict, ChanRestrict::DATE) != ChanRestrict::NONE)
				std::cout << "[" << _m.date << "]";
			if (operator&(chanRestrict, ChanRestrict::TIME) != ChanRestrict::NONE)
				std::cout << "[" << _m.time << "]";
			if (operator&(chanRestrict, ChanRestrict::FILENAME) != ChanRestrict::NONE)
				std::cout << "[" << _m.sourceFileName << "]";
			if (operator&(chanRestrict, ChanRestrict::FILELINE) != ChanRestrict::NONE)
				std::cout << "[Line: " << _m.sourceLineNumber << "]";

			std::cout << _m.data;
		}
	}

	void Channel::CloseFile()
	{
		if (file.is_open())
			file.close();
	}

} // namespace sl