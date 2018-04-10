#pragma once
#include <System/Event/EventHandler.h>

namespace pad	{
namespace sys	{
namespace evnt	{

EventHandler::EventHandler(std::function<void()>& _func) :
	m_func(_func)
{

}

void EventHandler::Invoke()
{
	m_func();
}

void EventHandler::operator()()
{
	m_func();
}

void EventHandler::operator=(std::function<void()>& _func)
{
	m_func = _func;
}

}  // namespace evnt
}  // namespace sys
}  // namespace pad