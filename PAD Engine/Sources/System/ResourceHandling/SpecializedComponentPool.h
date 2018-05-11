#pragma once
#include <System/ResourceHandling/IComponentPool.h>
#include <System/ResourceHandling/ObjectPool.h>

namespace pad	{
namespace sys	{
namespace res	{

#define DEFAULT_COMPONENT_COUNT 50u
#define DEFAULT_COMPONENT_GROWTH_COUNT 50u

template <
	typename T_type, 
	int T_initCount = DEFAULT_COMPONENT_COUNT, 
	int T_growthCount = DEFAULT_COMPONENT_GROWTH_COUNT>
class SpecializedComponentPool : public IComponentPool
{
public:
	SpecializedComponentPool()
	{

	}

	~SpecializedComponentPool()
	{

	}

protected:
	ObjectPool<T_type, T_initCount, T_initCount> m_pool;

public:
	template<typename ...Targs>
	ecs::AComponent* CreateComponent(Targs&&... _args)
	{
		T_type* object = &m_pool.GetItem();
		object = new (object) T_type(std::forward<Targs>(_args)...);
		return static_cast<ecs::AComponent*>(object);
	}

	void DeleteComponent(ecs::AComponent* const _comp) override
	{
		m_pool.SetItem(*static_cast<T_type*>(_comp));
	}

	std::list<T_type*>& GetActiveComponent()
	{
		return m_pool.GetActivePool();
	}
};

} // namespace res
} // namespace sys
} // namespace pad