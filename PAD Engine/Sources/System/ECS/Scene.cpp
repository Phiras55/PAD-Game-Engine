#include <System/ECS/Scene.h>

namespace pad	{
namespace sys	{
namespace ecs	{

Scene::Scene() :
	m_masterPADObject(new PADObject())
{
//	m_mainCamera = new gfx::PerspectiveCamera(&m_masterPADObject->GetTransform());
}

Scene::~Scene() 
{

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