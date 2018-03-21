#include "Scene.h"

namespace pad	{
namespace core	{

Scene::Scene() :
	masterPADObject(new PADObject())
{
}

Scene::~Scene() 
{

}

void Scene::Update()
{
	masterPADObject->Update();
}

void Scene::AddPADObject(PADObject * _PADObject)
{
	_PADObject->SetParent(masterPADObject);
}

//void Scene::Render()
//{
//
//}

} // namespace core
} // namespace pad