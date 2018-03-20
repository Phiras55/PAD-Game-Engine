#pragma once
#include "TPQueue.h"
#include "ThreadObject.h"

namespace pad {
namespace trp {

class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();
	
	void					Push(std::function<void()> _func);
	void					Stop();
	std::function<void()>	Pop();

private:
	void Init();

	std::vector<std::thread*>		m_threads;
	TPQueue<std::function<void()>>	m_queue;
	std::condition_variable			m_cv;
	std::mutex						m_mutex;
	bool							m_isActive;

};

}
}