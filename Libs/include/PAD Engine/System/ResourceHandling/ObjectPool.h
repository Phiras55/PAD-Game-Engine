#pragma once
#include <vector>
#include <System/ResourceHandling/PoolItem.h>

namespace pad	{
namespace sys	{
namespace res	{

template <typename T_type, int T_initCount, int T_growthCount>
class ObjectPool final
{
public:
	ObjectPool()
	{
		m_pool.reserve(T_initCount);
		m_pool.resize(T_initCount, PoolItem<T_type>());

		m_firstAvailable = &m_pool[0];

		for (int i = 0, count = m_pool.size() - 1; i < count; ++i)
		{
			m_pool[i].next = &m_pool[i + 1];
		}

		SetLastNextNull();
	}

	~ObjectPool()
	{

	}

	T_type& GetItem()
	{
		if (!m_firstAvailable)
		{
			GrowPool();
		}

		PoolItem<T_type>* first = m_firstAvailable;
		m_firstAvailable = first->next;
		return first->data;
	}

	void SetItem(T_type& _item)
	{
		for (int i = 0, count = m_pool.size(); i < count; ++i)
		{
			if (&_item == &m_pool[i].data)
			{
				PoolItem<T_type>* itemFound = &m_pool[i];
				itemFound->next = m_firstAvailable;

				m_firstAvailable = itemFound;
			}
		}
	}

private:
	void SetLastNextNull()
	{
		m_pool[m_pool.size() - 1].next = nullptr;
	}

	void GrowPool()
	{
		int oldSize = m_pool.size();
		m_pool.resize(oldSize + T_growthCount, PoolItem<T_type>());

		m_firstAvailable = &m_pool[oldSize];
		for (int i = oldSize, count = m_pool.size() - 1; i < count; ++i)
		{
			m_pool[i].next = &m_pool[i + 1];
		}

		SetLastNextNull();
	}

private:
	std::vector<PoolItem<T_type>>	m_pool;
	PoolItem<T_type>*				m_firstAvailable;
};

} // namespace res
} // namespace sys
} // namespace pad