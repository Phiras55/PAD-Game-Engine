#include <System/Event/Subject.h>
#include <System/Event/IObserver.h>

namespace pad	{
namespace sys	{
namespace evnt	{

void Subject::AddObserver(IObserver* const _obj)
{
	m_mutex.lock();
	m_observers.push_back(_obj);
	m_mutex.unlock();
}

void Subject::RemoveObserver(IObserver* const _obj)
{
	m_mutex.lock();
	m_observers.remove(_obj);
	m_mutex.unlock();
}

void Subject::Notify(EventArgs* const _args)
{
	m_mutex.lock();
	for (IObserver* const ob : m_observers)
	{
		ob->Update(this, _args);
	}
	m_mutex.unlock();
}

}  // namespace evnt
}  // namespace sys
}  // namespace pad