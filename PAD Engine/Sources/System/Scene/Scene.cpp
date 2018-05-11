#include <EnginePCH.h>
#include <System/Scene/Scene.h>

namespace pad	{
namespace sys	{
namespace ecs	{

Scene::Scene() : 
	m_masterPADObject(new PADObject())
{
	m_masterPADObject->SetName("MasterSceneObject");
}

Scene::~Scene() 
{
	delete m_masterPADObject;
}

void Scene::Init()
{
	m_masterPADObject->Init();

	m_mainCamera.Perspective(45.f, 16.f / 9.f, 0.01f, 1000.f);
	m_mainCamera.LookAt(math::Vec3f(15, 7, 7), math::Vec3f(0, 0, 0), math::Vec3f::Up());
}

void Scene::Start()
{
	m_masterPADObject->Start();
}

void Scene::Update()
{
	m_masterPADObject->Update();
}

void Scene::FixedUpdate()
{
	m_masterPADObject->FixedUpdate();
}

void Scene::LateUpdate()
{
	m_masterPADObject->LateUpdate();
}

void Scene::AddPADObject(PADObject * _PADObject)
{
	m_masterPADObject->AddChild(_PADObject);
}

json Scene::Serialize()
{
	json sceneJson;

	if (m_masterPADObject)
	{
		m_masterPADObject->Serialize();
	}

	return sceneJson;
}

void Scene::Deserialize(const json& _j)
{
	m_masterPADObject->Deserialize(_j);
}

PADObject* Scene::GetPADObject(const std::string& _name, PADObject* const _rootSearch)
{
	PADObject* entity = nullptr;
	PADObject* root = (_rootSearch ? _rootSearch : m_masterPADObject);

	return FindPADObject(_name, root);
}

PADObject* Scene::CreatePADObject(const std::string& _name, PADObject* const _parent)
{
	PADObject* entity = new PADObject();
	entity->SetName(_name);

	if (_parent)
		entity->SetParent(_parent);
	else
		m_masterPADObject->AddChild(entity);

	return entity;
}

void Scene::DeletePADObject(const std::string& _name, PADObject* const _rootSearch)
{
	PADObject* objectFound = GetPADObject(_name, _rootSearch);

	if (objectFound)
	{
		delete objectFound;
	}
}

PADObject* Scene::FindPADObject(const std::string& _name, PADObject* const _rootSearch)
{
	PADObject* resultEntity = nullptr;

	if (_rootSearch)
	{
		if (_rootSearch->GetName() == _name)
			return _rootSearch;

		for (PADObject* const p : _rootSearch->GetChildren())
		{
			resultEntity = FindPADObject(_name, p);

			if (resultEntity)
				break;
		}
	}

	return resultEntity;
}

} // namespace ecs
} // namespace sys
} // namespace pad