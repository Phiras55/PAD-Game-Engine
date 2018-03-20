#pragma once
#include <queue>
#include <mutex>
#include <stdexcept>

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
	T Pop()
	{
		std::lock_guard<std::mutex> lg(mutex);
		if (IsEmpty())
			throw std::out_of_range("Queue is empty");
		else
		{
			T temp = queue.front();
			return temp;
		}
	}
	bool Clear()
	{
		if (!IsEmpty())
			while (Pop())
				;
		return true;
	}
	bool IsEmpty()
	{
		return queue.empty();
	}

	std::queue<T>	queue;
	std::mutex		mutex;
};
}
}