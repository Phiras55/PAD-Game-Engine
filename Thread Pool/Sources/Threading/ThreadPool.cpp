#include "ThreadPool.h"

namespace pad {
namespace trp {

ThreadPool::ThreadPool()
{
	Init();
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::Push(std::function<void()> _task)
{
	m_queue.Push(_task);
}

void ThreadPool::Stop()
{
	m_queue.Clear();

}

void ThreadPool::Init()
{

}

std::function<void()> ThreadPool::Pop()
{
	return m_queue.Pop();
}








}
}