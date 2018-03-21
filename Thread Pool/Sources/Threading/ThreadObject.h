#pragma once
#include <thread>
#include <atomic>

namespace pad {
namespace trp {

class ThreadPool;

class ThreadObject final
{
public:
	ThreadObject() = delete;
	ThreadObject(ThreadPool* _tp);
	~ThreadObject();

private:
	ThreadPool*				m_threadPool;
	std::thread				m_thread;
	std::function<void()>	m_func;
	std::atomic_bool		m_active;

private:
	void Start();
	bool LookForTask();
	void Stop();
};

}
}