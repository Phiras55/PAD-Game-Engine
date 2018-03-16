#include "ThreadObject.h"

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

	bool ThreadObject::LookForTask()
	{
		return false;
	}

	void ThreadObject::Stop()
	{
	}

}
}