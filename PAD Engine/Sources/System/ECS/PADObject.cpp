#include <EnginePCH.h>
#include <System/ECS/PADObject.h>
#include <System/ECS/AComponent.h>

namespace pad	{
namespace sys	{
namespace ecs	{

res::ComponentsHandler*	PADObject::m_componentHandlerHandle = nullptr;

PADObject::PADObject() :
	m_parent(nullptr),
	m_dontDestroy(false),
	m_collider(nullptr)
{
	m_components.reserve(MAX_COMPONENT_COUNT);
	m_components.resize(MAX_COMPONENT_COUNT);
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

	for (int i = 0, count = m_components.size(); i < count; ++i)
	{
		if (m_hasComponent[i] && m_components[i])
			m_componentHandlerHandle->RemoveComponent(m_components[i], m_components[i]->GetType());
	}

	for (PADObject* so : m_childs)
	{
		so->m_parent = nullptr;
		so->~PADObject();
	}
}

void PADObject::SetParent(PADObject* const _parent)
{
	/*if (m_parent)
		m_parent->RemoveChild(this);

	_parent->AddChild(this);*/

	m_parent = _parent;
	
	if (m_parent)
		m_parent->AddChild(this);
}

void PADObject::AddChild(PADObject* const _child)
{
	/*if (_child->m_parent)
		_child->m_parent->RemoveChild(_child);

	_child->m_parent = this;
	m_childs.push_back(_child);*/

	if (_child)
	{
		m_childs.push_back(_child);
		m_childs.unique();
	}
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

	for (PADObject* so : m_childs)
		so->Update();
}

void PADObject::FixedUpdate()
{
	for (AComponent* const comp : m_components)
		if(comp)
			comp->FixedUpdate();

	for (PADObject* so : m_childs)
		so->FixedUpdate();
}

void PADObject::LateUpdate()
{
	for (AComponent* const comp : m_components)
		if (comp)
			comp->LateUpdate();

	for (PADObject* so : m_childs)
		so->LateUpdate();
}

void PADObject::Init()
{
	for (AComponent* const comp : m_components)
		if (comp)
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

	for (AComponent* const comp : m_components)
		if (comp)
			comp->Start();

	for (PADObject* so : m_childs)
		so->Start();
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
	for (AComponent* const component : m_components)
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