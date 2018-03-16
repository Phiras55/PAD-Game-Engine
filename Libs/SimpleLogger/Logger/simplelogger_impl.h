#pragma once

using namespace sl;

template<typename T, typename... Targs>
void SimpleLogger::Log(
	const char*				_sourceFileName,
	const int				_sourceLine,
	const char*				_date,
	const char*				_time,
	const E_CHANNEL_TYPE	_chan,
	const std::string&		_format,
	const T&				_arg,
	Targs&&...				_args)
{
	Message m(_chan, StripPath(_sourceFileName), _time, _date, _sourceLine);

	BuildMessage(_format, m, 0, _arg, _args...);

	m_mutex.lock();
	m_messages.push(m);
	m_mutex.unlock();
}

template<typename T, typename... Targs>
static void SimpleLogger::BuildMessage(const std::string& _format, Message& _m, int _findStart, const T& _a, Targs&&... _args)
{
	const int findBegin = (_findStart == 0 ? _findStart : _findStart + 1);
	_findStart = _format.find(CPARAMETER, _findStart);

	if (_findStart != std::string::npos)
	{
		_m.data += _format.substr(findBegin, _findStart - findBegin);
		_m.data += std::to_string(_a);

		if constexpr (sizeof...(_args))
		{
			BuildMessage(_format, _m, _findStart + 1, _args...);
			return;
		}
		else
		{
			// The parameter is 2 character long so +2 to the start to not include it.
			_m.data.append(_format.substr(_findStart + 2));
			return;
		}
	}

	_m.data += _format.substr(findBegin);
}