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
	
	void Push(std::function<void()>*);
	void Stop();

private:
	void Init();
	std::function<void()>* Pop();

	std::vector<std::thread*>		Threads;
	TPQueue<std::function<void()>*> Queue;
	std::condition_variable			Cv;
	std::mutex						Mutex;
	bool							IsActive;
	int								WaitingThreads;

};

}
}