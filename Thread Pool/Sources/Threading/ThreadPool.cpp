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

void ThreadPool::Push(std::function<void()>* _task)
{
	Queue.Push(_task);
}

void ThreadPool::Stop()
{
	Queue.Clear();
}

void ThreadPool::Init()
{

}

std::function<void()>* ThreadPool::Pop()
{
	return new std::function<void()>();
}








}
}