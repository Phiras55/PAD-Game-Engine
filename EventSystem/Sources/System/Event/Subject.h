#pragma once
#include <list>
#include <mutex>

namespace pad	{
namespace sys	{
namespace evnt	{

class Subject
{
protected:
	std::list<class IObserver*>	m_observers;
	std::mutex					m_mutex;

public:
	void AddObserver(class IObserver* const _obj);
	void RemoveObserver(class IObserver* const _obj);
	void Notify(struct EventArgs* const _args);
};

}  // namespace evnt
}  // namespace sys
}  // namespace pad