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
		std::lock_guard<std::mutex>(mutex);
		queue.push(task);
	}
	bool Pop()
	{
		std::lock_guard<std::mutex>(mutex);
		if (IsEmpty())
			return false;
		else
			queue.pop();
		return true;
	}
	bool Clear()
	{
		if (!IsEmpty())
			while (Pop());
		return true;
	}
	bool IsEmpty()
	{
		return queue.empty();
	}

	std::queue<T> queue;
	std::mutex mutex;
};

}
}