#pragma once
#include <functional>

namespace pad	{
namespace sys	{
namespace evnt	{

class EventHandler
{
public:
	EventHandler() = default;
	EventHandler(std::function<void()>& _func);
	~EventHandler() = default;

private:
	std::function<void()> m_func;

public:
	void Invoke();

public:
	void operator()();
	void operator=(std::function<void()>& _func);
};

}  // namespace evnt
}  // namespace sys
}  // namespace pad