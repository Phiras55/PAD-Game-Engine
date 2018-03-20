#include "ThreadObject.h"
#include "ThreadPool.h"

namespace pad {
namespace trp {

	ThreadObject::ThreadObject(ThreadPool & _tp) : 
		m_threadPool(_tp)
	{
		Start();
	}

	ThreadObject::~ThreadObject()
	{
		Stop();
	}

	void ThreadObject::Start()
	{
	}

	void ThreadObject::LookForTask()
	{
		m_func = m_threadPool.Pop();
		if (m_func == nullptr)
			return;
	}

	void ThreadObject::Stop()
	{
	}

}
}