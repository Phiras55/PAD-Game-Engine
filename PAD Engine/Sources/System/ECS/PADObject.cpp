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
	m_components.reserve(MAX_COMPONENT_COUNT);
	m_components.resize(MAX_COMPONENT_COUNT);
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
	m_parent = _parent;
	
	if (m_parent)
		m_parent->AddChild(this);
}

void PADObject::AddChild(PADObject* const _child)
{
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

	int componentCount = 0;
	for (int i = 0, count = m_components.size(); i < count; ++i)
	{
		if (m_hasComponent[i])
		{
			AddDataToJson(j, std::string("componentName") + std::to_string(componentCount), m_components[i]->GetName());
			AddDataToJson(j, std::string("componentData") + std::to_string(componentCount), m_components[i]->Serialize());
			++componentCount;
		}
	}

	AddDataToJson(j, "componentCount", componentCount);

	int i = 0;
	AddDataToJson(j, "childCount", m_childs.size());
	for (PADObject* const child : m_childs)
	{
		AddDataToJson(j, std::string("child") + std::to_string(i), child->Serialize());
		++i;
	}

	return j;
}

void PADObject::Deserialize(const json& _j)
{
	m_transform.Deserialize(JsonToData<json>(_j, "m_transform"));
	m_dontDestroy =			JsonToData<bool>(_j, "m_dontDestroy");
	m_name =				JsonToData<std::string>(_j, "m_name");

	int componentCount = JsonToData<size_t>(_j, "componentCount");
	AComponent* comp = nullptr;
	for (int i = 0; i < componentCount; ++i)
	{
		comp = AddComponentFromName(JsonToData<std::string>(_j, std::string("componentName") + std::to_string(i)));
		comp->Deserialize(JsonToData<json>(_j, "componentData" + std::to_string(i)));
	}

	int childCount = JsonToData<size_t>(_j, "childCount");
	PADObject* currentChild = nullptr;
	for (int i = 0; i < childCount; ++i)
	{
		currentChild = new PADObject(this);
		currentChild->Deserialize(JsonToData<json>(_j, std::string("child") + std::to_string(i)));
		m_childs.push_back(currentChild);
	}
}

AComponent* const PADObject::AddComponentFromName(const std::string& _name)
{
	AComponent* comp = nullptr;
	if (_name == "PerspectiveCamera")
		comp = AddComponent<PerspectiveCamera>();
	else if (_name == "RigidBody")
		comp = AddComponent<RigidBody>();
	else if (_name == "BoxCollider")
		comp = AddComponent<BoxCollider>();
	else if (_name == "DirectionalLight")
		comp = AddComponent<DirectionalLight>();
	else if (_name == "MeshRenderer")
		comp = AddComponent<MeshRenderer>();
	else
		comp = AddComponent<AnimRenderer>();

	return comp;
}

} // namespace ecs
} // namespace sys
} // namespace pad