#include <EnginePCH.h>
#include <System/ResourceHandling/ComponentsHandler.h>

namespace pad	{
namespace sys	{
namespace res	{

ComponentsHandler::ComponentsHandler()
{
#pragma region MeshRenderers
	alias::MeshRendererPool* meshRendererPool			= new alias::MeshRendererPool();
	ecs::MeshRenderer* m								= static_cast<ecs::MeshRenderer*>(meshRendererPool->CreateComponent());

	m_pools[m->GetType()] = meshRendererPool;
	meshRendererPool->DeleteComponent(m);
#pragma endregion

#pragma region RigidBodys
	alias::RigidBodyPool* rigidBodyPool					= new alias::RigidBodyPool();
	ecs::RigidBody* r									= static_cast<ecs::RigidBody*>(rigidBodyPool->CreateComponent());

	m_pools[r->GetType()] = rigidBodyPool;
	rigidBodyPool->DeleteComponent(r);
#pragma endregion

#pragma region BoxColliders
	alias::BoxColliderPool* boxColliderPool				= new alias::BoxColliderPool();
	ecs::BoxCollider* b									= static_cast<ecs::BoxCollider*>(boxColliderPool->CreateComponent());

	m_pools[b->GetType()] = boxColliderPool;
	boxColliderPool->DeleteComponent(b);
#pragma endregion

#pragma region PerpectiveCameras
	alias::PerspectiveCameraPool* perspectiveCameraPool = new alias::PerspectiveCameraPool();
	ecs::PerspectiveCamera* p							= static_cast<ecs::PerspectiveCamera*>(perspectiveCameraPool->CreateComponent());

	m_pools[p->GetType()] = perspectiveCameraPool;
	p->GetType();
	perspectiveCameraPool->DeleteComponent(p);
#pragma endregion

#pragma region AnimRenderer
	alias::AnimRendererPool* animRendererPool			= new alias::AnimRendererPool();
	ecs::AnimRenderer* a								= static_cast<ecs::AnimRenderer*>(animRendererPool->CreateComponent());

	m_pools[a->GetType()] = animRendererPool;
	a->GetType();
	animRendererPool->DeleteComponent(a);
#pragma endregion
}

ComponentsHandler::~ComponentsHandler()
{
	for (auto& it : m_pools)
	{
		delete it.second;
	}
	m_pools.clear();
}



} // namespace res
} // namespace sys
} // namespace pad