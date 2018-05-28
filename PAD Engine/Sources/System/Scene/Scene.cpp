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

	PADObject* light, *camera;

	light =  CreatePADObject("DirectionalLight", m_masterPADObject);
	camera = CreatePADObject("MainCamera", m_masterPADObject);

	light->AddComponent<DirectionalLight>();
	light->GetTransform().SetRotation(math::Vec3f(0.f, 180.f, 0.f));
	m_directionalLight = light->GetComponent<DirectionalLight>();

	if (m_directionalLight)
	{
		m_directionalLight->SetColor(math::Vec3f(255.f / 255.f, 244.f / 255.f, 214.f / 255.f));
		m_directionalLight->SetIntensity(1.f);
	}

	camera->AddComponent<PerspectiveCamera>();
	m_mainCamera = camera->GetComponent<PerspectiveCamera>();

	if (m_mainCamera)
	{
		m_mainCamera->Perspective(45.f, 16.f / 9.f, 0.01f, 1000.f);
		m_mainCamera->GetOwner()->GetTransform().SetPosition(math::Vec3f(0, 5, -10));
	}
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

void Scene::AddPADObject(PADObject* _PADObject)
{
	m_masterPADObject->AddChild(_PADObject);
}

void Scene::Serialize(const std::string& _savePath)
{
	json j;

	if (m_masterPADObject)
		j = m_masterPADObject->Serialize();

	AddJsonToFile(_savePath, j);
}

void Scene::Deserialize(const std::string& _savePath)
{
	json j = LoadJsonFromFile(_savePath);
	
	if (m_masterPADObject)
	{
		m_masterPADObject->Deserialize(j);
		m_directionalLight = GetPADObject("DirectionalLight")->GetComponent<DirectionalLight>();
		m_mainCamera = GetPADObject("MainCamera")->GetComponent<PerspectiveCamera>();
	}
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

void Scene::DeletePADObject(PADObject* const _object)
{
	delete _object;
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