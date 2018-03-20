#pragma once
#include "TPQueue.h"
#include "ThreadObject.h"

namespace pad {
namespace trp {

class ThreadPool
{
public:
	ThreadPool() = delete;
	ThreadPool(const unsigned int& _threadsCount = 4u);
	~ThreadPool();
	
	void					Push(std::function<void()> _func);
	void					Stop();
	std::function<void()>	TakeTask();
	void					Clear();

	bool					Lock();
	void					Unlock();

	bool					IsEmpty();
	bool					IsActive();


private:
	void Init(const unsigned int& _threadCount);

	std::vector<ThreadObject*>		m_threads;
	TPQueue<std::function<void()>>	m_queue;
	std::mutex						m_mutex;
	std::atomic_bool				m_isActive;

};

}
}