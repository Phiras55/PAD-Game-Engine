#include <SimpleLogger.h>

using namespace sl;

std::queue<Message>			SimpleLogger::m_messages;
std::map<ChanType, Channel> SimpleLogger::m_channels;
std::mutex					SimpleLogger::m_mutex;

SimpleLogger::SimpleLogger()
{

}

SimpleLogger::~SimpleLogger()
{

}

void SimpleLogger::Init()
{
	const char* defaultFolder = "Logs";
	m_channels[ChanType::INFO].filePath = defaultFolder;
	m_channels[ChanType::INFO].fileName = "info.log";

	m_channels[ChanType::WARNING].filePath = defaultFolder;
	m_channels[ChanType::WARNING].fileName = "warning.log";

	m_channels[ChanType::TRACE].filePath = defaultFolder;
	m_channels[ChanType::TRACE].fileName = "trace.log";

	m_channels[ChanType::ERROR].filePath = defaultFolder;
	m_channels[ChanType::ERROR].fileName = "error.log";

	m_channels[ChanType::FATAL].filePath = defaultFolder;
	m_channels[ChanType::FATAL].fileName = "fatal.log";
}

void SimpleLogger::Flush()
{
	m_mutex.lock();
	while (m_messages.size() > 0)
	{
		ShowMessage(m_messages.front());
		m_messages.pop();
	}
	m_mutex.unlock();

	CloseFiles();
}

void SimpleLogger::ShowMessage(const Message& _m)
{
	if (operator&(_m.channels, ChanType::INFO) != ChanType::NONE)
		m_channels[ChanType::INFO].WriteLine(_m);

	if (operator&(_m.channels, ChanType::TRACE) != ChanType::NONE)
		m_channels[ChanType::TRACE].WriteLine(_m);

	if (operator&(_m.channels, ChanType::WARNING) != ChanType::NONE)
		m_channels[ChanType::WARNING].WriteLine(_m);

	if (operator&(_m.channels, ChanType::ERROR) != ChanType::NONE)
		m_channels[ChanType::ERROR].WriteLine(_m);

	if (operator&(_m.channels, ChanType::FATAL) != ChanType::NONE)
		m_channels[ChanType::FATAL].WriteLine(_m);
}

void SimpleLogger::CloseFiles()
{
	for (auto& c : m_channels)
		c.second.CloseFile();
}

void SimpleLogger::SetChannelOutput(const ChanType _chan, const ChanOutput _output)
{
	if (operator&(_chan, ChanType::INFO) != ChanType::NONE)
		m_channels[ChanType::INFO].chanOutput = _output;

	if (operator&(_chan, ChanType::TRACE) != ChanType::NONE)
		m_channels[ChanType::TRACE].chanOutput = _output;

	if (operator&(_chan, ChanType::WARNING) != ChanType::NONE)
		m_channels[ChanType::WARNING].chanOutput = _output;

	if (operator&(_chan, ChanType::ERROR) != ChanType::NONE)
		m_channels[ChanType::ERROR].chanOutput = _output;

	if (operator&(_chan, ChanType::FATAL) != ChanType::NONE)
		m_channels[ChanType::FATAL].chanOutput = _output;
}

void SimpleLogger::SetChannelRestriction(const ChanType _chan, const ChanRestrict _r)
{
	if (operator&(_chan, ChanType::INFO) != ChanType::NONE)
		m_channels[ChanType::INFO].chanRestrict = _r;

	if (operator&(_chan, ChanType::TRACE) != ChanType::NONE)
		m_channels[ChanType::TRACE].chanRestrict = _r;

	if (operator&(_chan, ChanType::WARNING) != ChanType::NONE)
		m_channels[ChanType::WARNING].chanRestrict = _r;

	if (operator&(_chan, ChanType::ERROR) != ChanType::NONE)
		m_channels[ChanType::ERROR].chanRestrict = _r;

	if (operator&(_chan, ChanType::FATAL) != ChanType::NONE)
		m_channels[ChanType::FATAL].chanRestrict = _r;
}