#pragma once
#include <queue>
#include <mutex>

namespace pad {
namespace trp {

template <typename T>
struct TPQueue final
{
	void Push(T task)
	{
		std::lock_guard<std::mutex> lg(mutex);
		queue.push(task);
	}
	void Pop()
	{
		std::lock_guard<std::mutex> lg(mutex);
		queue.pop();
	}
	T Front()
	{
		std::lock_guard<std::mutex> lg(mutex);
		return queue.front();
	}
	unsigned int Size()
	{
		std::lock_guard<std::mutex> lg(mutex);
		return queue.size();
	}
	bool Clear()
	{
		if (!IsEmpty())
			while (!IsEmpty())
				Pop();
		return true;
	}
	bool IsEmpty()
	{
		std::lock_guard<std::mutex> lg(mutex);
		return queue.empty();
	}

	std::queue<T>	queue;
	std::mutex		mutex;
};
}
}