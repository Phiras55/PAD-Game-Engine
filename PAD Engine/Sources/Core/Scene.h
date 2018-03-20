#pragma once

#include <vector>
#include <Core/SceneObject.h>

namespace pad	{
namespace core	{

class Scene final
{
#pragma region Constructor / Destructor

public:
	Scene();
	~Scene();

	Scene(const Scene&)		= delete;
	Scene(const Scene&&)	= delete;

#pragma endregion


public:
	SceneObject* masterSceneObject;

public:
	void Update();
	void AddSceneObject(SceneObject* _sceneObject);
//	void Render();
};

} // namespace core
} // namespace pad