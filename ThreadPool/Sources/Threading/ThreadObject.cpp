#include "ThreadObject.h"
#include "ThreadPool.h"

namespace pad {
namespace trp {

	ThreadObject::ThreadObject(ThreadPool* _tp) : 
		m_threadPool(_tp),
		m_thread(&ThreadObject::Start, this)
	{
	}

	ThreadObject::~ThreadObject()
	{
		Stop();
	}

	void ThreadObject::Start()
	{
		m_active.store(true);
		while (m_active.load() && m_threadPool->IsActive())
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(378));
			while (m_active.load() && LookForTask())
			{
				m_func();
			}
		}
	}

	bool ThreadObject::LookForTask()
	{
		if (!m_threadPool->Lock())
			return false;
		if (m_threadPool->IsEmpty())
		{
			m_threadPool->Unlock();
			return false;
		}
		else
		{
			m_func = m_threadPool->TakeTask();
			m_threadPool->Unlock();
			return true;
		}
	}

	void ThreadObject::Stop()
	{
		m_active.store(false);
		m_thread.join();
	}

}
}