#pragma once

namespace pad	{
namespace sys	{
namespace res	{

template <typename T_type>
struct PoolItem final
{
	PoolItem()
	{

	}
	PoolItem(const PoolItem& p)
	{
		data = p.data;
		next = p.next;
	}
	~PoolItem()
	{

	}

	T_type				data;
	PoolItem<T_type>*	next = nullptr;
};

} // namespace res
} // namespace sys
} // namespace pad