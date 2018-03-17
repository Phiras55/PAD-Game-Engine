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


private:
	std::vector<SceneObject*> sceneObjects;

public:
	void Update();
	void Render();
};

} // namespace core
} // namespace pad