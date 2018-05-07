#include <EnginePCH.h>
#include <System/ECS/PADObject.h>
#include <System/ECS/IComponent.h>

namespace pad	{
namespace sys	{
namespace ecs	{

PADObject::PADObject() :
	m_parent(nullptr),
	m_dontDestroy(false)
{

}

PADObject::PADObject(PADObject* const _parent) :
	m_parent(_parent),
	m_dontDestroy(false)
{

}

PADObject::~PADObject()
{
	if (m_parent)
		m_parent->RemoveChild(this);

	for (PADObject* so : m_childs)
	{
		so->m_parent = nullptr;
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
	if (m_parent)
	{
		m_transform.SetGlobalTransform(		m_parent->m_transform.GetGlobalTransform()
										*	m_transform.GetLocalTransform());
	}
	else
		m_transform.SetGlobalTransform(m_transform.GetLocalTransform());


	for (IComponent* comp : m_components)
	{
		if (comp->GetType() != SCRIPT)
			comp->Update();
	}

	for (PADObject* so : m_childs)
		so->Update();
}

void PADObject::FixedUpdate()
{
	for (IComponent* comp : m_components)
		comp->FixedUpdate();

	for (PADObject* so : m_childs)
		so->FixedUpdate();
}

void PADObject::LateUpdate()
{
	for (IComponent* comp : m_components)
		comp->LateUpdate();

	for (PADObject* so : m_childs)
		so->LateUpdate();
}

void PADObject::AddComponent(IComponent* const _component)
{
	_component->SetOwner(this);
	m_components.push_back(_component);
}

void PADObject::RemoveComponent(IComponent* const _component)
{
	m_components.remove(_component);
}

void PADObject::Init()
{
	for (IComponent* comp : m_components)
		comp->Init();

	for (PADObject* so : m_childs)
		so->Init();
}

void PADObject::Start()
{
	if (m_parent)
	{
		m_transform.SetGlobalTransform(		m_parent->m_transform.GetGlobalTransform()
										*	m_transform.GetLocalTransform());
	}
	else
		m_transform.SetGlobalTransform(m_transform.GetLocalTransform());

	for (IComponent* comp : m_components)
		comp->Start();

	for (PADObject* so : m_childs)
		so->Start();
}

void PADObject::SetParent(PADObject* const _parent)
{
	if (m_parent)
		m_parent->RemoveChild(this);

	_parent->AddChild(this);
}

json PADObject::Serialize()
{
	json j;

	AddDataToJson(j, "m_transform", m_transform.Serialize());
	AddDataToJson(j, "m_dontDestroy", m_dontDestroy);
	AddDataToJson(j, "m_name", m_name);
	AddDataToJson(j, "componentCount", m_components.size());
	AddDataToJson(j, "childrenCount", m_childs.size());

	int i = 0;
	for (IComponent* const component : m_components)
	{
		AddDataToJson(j, std::string("componentType") + std::to_string(i), component->GetType());
		AddDataToJson(j, std::string("componentType") + std::to_string(i), component->Serialize());
		++i;
	}

	return j;
}

void PADObject::Deserialize(const json& j)
{

}

} // namespace ecs
} // namespace sys
} // namespace pad