#include "Scene.h"

namespace pad	{
namespace core	{

Scene::Scene() :
	masterSceneObject(new SceneObject())
{
}

Scene::~Scene() 
{

}

void Scene::Update()
{
	masterSceneObject->Update();
}

void Scene::AddSceneObject(SceneObject * _sceneObject)
{
	_sceneObject->SetParent(masterSceneObject);
}

//void Scene::Render()
//{
//
//}

} // namespace core
} // namespace pad