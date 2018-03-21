#include "ThreadPool.h"

namespace pad {
namespace trp {

ThreadPool::ThreadPool(const unsigned int& _threadCount)
{
	Init(_threadCount);
}

ThreadPool::~ThreadPool()
{
	Clear();
}

void ThreadPool::Push(std::function<void()> _task)
{
	m_queue.Push(_task);
}

std::function<void()> ThreadPool::TakeTask()
{
	std::function<void()> f = m_queue.Front();
	m_queue.Pop();
	return f;
}

void ThreadPool::Stop()
{
	m_isActive.store(false);
	m_queue.Clear();
}

void ThreadPool::Clear()
{
	Stop();
	for (unsigned int i = 0; i < m_threads.size(); ++i)
	{
		delete(m_threads.back());
		m_threads.pop_back();
	}
}

bool ThreadPool::Lock()
{
	return m_mutex.try_lock();
}

void ThreadPool::Unlock()
{
	m_mutex.unlock();
}

bool ThreadPool::IsEmpty()
{
	return m_queue.IsEmpty();
}

bool ThreadPool::IsActive()
{
	return m_isActive;
}

void ThreadPool::Init(const unsigned int& _threadCount)
{
	m_isActive.store(true);
	m_threads.resize(_threadCount);
	for (unsigned char i = 0; i < _threadCount; ++i)
	{
		m_threads.push_back(new ThreadObject(this));
	}
}
}
}