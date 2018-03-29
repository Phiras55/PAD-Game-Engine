#include <System/ECS/PADObject.h>
#include <algorithm>

namespace pad	{
namespace sys	{
namespace ecs	{

PADObject::PADObject() :
	m_parent(nullptr),
	m_dontDestroy(false)
{

}

PADObject::PADObject(PADObject* const _parent) :
	m_parent(_parent)
{

}

PADObject::~PADObject()
{
	if (m_parent)
		m_parent->RemoveChild(this);

	for (PADObject* so : m_childs)
	{
		so->SetParent(nullptr);
		so->~PADObject();
	}
}

void PADObject::AddChild(PADObject* const _child)
{
	if (_child->m_parent)
		_child->m_parent->RemoveChild(_child);

	_child->m_parent = this;
	m_childs.push_back(_child);
}

void PADObject::RemoveChild(PADObject* const _child)
{
	m_childs.remove(_child);
}

void PADObject::Update()
{
	for (IComponent* comp : m_components)
		comp->Update();

	m_transform.SetGlobalTransform(		m_parent->m_transform.GetGlobalTransform() 
									*	m_transform.GetLocalTransform());

	for (PADObject* so : m_childs)
		so->Update();
}

void PADObject::FixedUpdate()
{
}

void PADObject::LateUpdate()
{
}

void PADObject::AddComponent(IComponent* const _component)
{
	m_components.push_back(_component);
}

void PADObject::RemoveComponent(IComponent * const _component)
{
	m_components.remove(_component);
}

void PADObject::Init()
{
}

void PADObject::Start()
{
}

void PADObject::SetParent(PADObject* const _parent)
{
	if (m_parent)
		m_parent->RemoveChild(this);

	m_parent = _parent;
	_parent->AddChild(this);
}

} // namespace ecs
} // namespace sys
} // namespace pad