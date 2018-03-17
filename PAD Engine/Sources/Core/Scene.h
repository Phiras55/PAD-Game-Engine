#pragma once

#include <vector>
#include <Core/SceneObject.h>

namespace pad	{
namespace core	{

class Scene final
{
#pragma region Constructor / Destructor

public:
	Scene()		= default;
	~Scene();

	Scene(const Scene&)		= delete;
	Scene(const Scene&&)	= delete;

#pragma endregion


public:
	static SceneObject* masterSceneObject;

public:
	void Update();
	void AddSceneObject(SceneObject* _sceneObject);
//	void Render();
};

} // namespace core
} // namespace pad