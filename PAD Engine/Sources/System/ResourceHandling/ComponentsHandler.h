#pragma once
#include <System/ResourceHandling/SpecializedComponentPool.h>
#include <System/ECS/RigidBody.h>
#include <System/ECS/BoxCollider.h>
#include <System/ECS/MeshRenderer.h>
#include <System/ECS/PerspectiveCamera.h>

namespace pad	{
namespace sys	{
namespace res	{

namespace alias {
	using ComponentHashTable	= std::unordered_map<ecs::alias::ComponentID, res::IComponentPool*>;
	using RigidBodyPool			= SpecializedComponentPool<ecs::RigidBody>;
	using BoxColliderPool		= SpecializedComponentPool<ecs::BoxCollider>;
	using MeshRendererPool		= SpecializedComponentPool<ecs::MeshRenderer>;
	using PerspectiveCameraPool = SpecializedComponentPool<ecs::PerspectiveCamera>;
} // namespace alias

class ComponentsHandler final
{
public:
	ComponentsHandler();
	~ComponentsHandler();

	ComponentsHandler(const ComponentsHandler&) = delete;
	ComponentsHandler(ComponentsHandler&&)		= delete;

private:
	alias::ComponentHashTable m_pools;

public:
	template<typename T, typename ...Targs>
	T* CreateComponent(Targs&&... _args)
	{
		static_assert(std::is_base_of<ecs::AComponent, T>::value, "T must be of type AComponent");
		T* result = nullptr;
		if (m_pools.find(util::GetTypeID<T>()) != m_pools.end())
		{
			auto pool = static_cast<SpecializedComponentPool<T, DEFAULT_COMPONENT_COUNT, DEFAULT_COMPONENT_GROWTH_COUNT>*>(m_pools[util::GetTypeID<T>()]);
			result = static_cast<T*>(pool->CreateComponent<Targs...>(std::forward<Targs>(_args)...));
		}
		return result;
	}

	template<typename T>
	void RemoveComponent(ecs::AComponent* const _comp)
	{
		if (m_pools.find(util::GetTypeID<T>()) != m_pools.end())
		{
			m_pools[util::GetTypeID<T>()]->DeleteComponent(_comp);
		}
	}

public:
	void operator=(const ComponentsHandler&)	= delete;
	void operator=(ComponentsHandler&&)			= delete;
};

} // namespace res
} // namespace sys
} // namespace pad