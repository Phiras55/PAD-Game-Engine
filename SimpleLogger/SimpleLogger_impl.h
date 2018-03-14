#pragma once

using namespace sl;

template<typename T, typename... Targs>
void SimpleLogger::Log(
	const char* _sourceFileName,
	const int _sourceLine,
	const char* _date,
	const char* _time,
	const E_CHANNEL_TYPE _chan,
	const std::string& _format,
	const T& _arg,
	Targs&&... _args)
{
	//if(sizeof...(_args))
}