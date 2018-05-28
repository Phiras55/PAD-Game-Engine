#pragma once
#include <vector>
#include <PoolItem.h>

template <typename T_type, int T_initCount, int T_growthCount>
class ItemPool final
{
public:
	ItemPool()
	{
		m_pool.reserve(T_initCount);
		m_pool.resize(T_initCount);

		m_firstAvailable = &m_pool[0];

		for (int i = 0, count = m_pool.size() - 1; i < count; ++i)
		{
			m_pool[i].data = i;
			m_pool[i].next = &m_pool[i + 1];
		}

		SetLastNextNull();
	}

	~ItemPool()
	{

	}

	T_type& GetItem()
	{
		if (!m_firstAvailable)
		{
			int oldSize = m_pool.size();
			m_pool.resize(oldSize + T_growthCount);

			m_firstAvailable = &m_pool[oldSize];
			for (int i = oldSize, count = m_pool.size() - 1; i < count; ++i)
			{
				m_pool[i].next = &m_pool[i + 1];
			}

			SetLastNextNull();
		}

		PoolItem<T_type>* first = m_firstAvailable;
		m_firstAvailable = first->next;
		first->next = nullptr;
		return first->data;
	}

	void SetItem(T_type& _item)
	{
		for (int i = 0, count = m_pool.size(); i < count; ++i)
		{
			if (&_item == &m_pool[i].data)
			{
				m_firstAvailable = &m_pool[i];
			}
		}
	}

private:
	void SetLastNextNull()
	{
		m_pool[m_pool.size() - 1].next = nullptr;
	}

private:
	std::vector<PoolItem<T_type>>	m_pool;
	PoolItem<T_type>*				m_firstAvailable;
};