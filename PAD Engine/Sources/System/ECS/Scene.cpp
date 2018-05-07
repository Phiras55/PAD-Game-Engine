#include <EnginePCH.h>
#include <System/ECS/Scene.h>

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

} // namespace ecs
} // namespace sys
} // namespace pad