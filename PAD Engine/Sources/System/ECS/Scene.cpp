#include <System/ECS/Scene.h>

namespace pad	{
namespace sys	{
namespace ecs	{

Scene::Scene() :
	m_masterPADObject(new PADObject())
{

}

Scene::~Scene() 
{

}

void Scene::Init()
{
	m_masterPADObject->Init();
}

void Scene::Update()
{
	m_masterPADObject->Update();
}

void Scene::AddPADObject(PADObject * _PADObject)
{
	_PADObject->SetParent(m_masterPADObject);
}

} // namespace ecs
} // namespace sys
} // namespace pad