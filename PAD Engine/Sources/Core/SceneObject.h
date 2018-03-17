#pragma once

#include <vector>
#include <Math/Transform.h>

namespace pad	{
namespace core	{

class SceneObject
{
#pragma region Constructor / Destructor

public:
	SceneObject();
	~SceneObject()	= default;

	SceneObject(const SceneObject&)		= delete;
	SceneObject(const SceneObject&&)	= delete;

#pragma endregion

#pragma region Variables

private:
	Transform					transform;
	std::vector<SceneObject*>	children;
	SceneObject*				parent;

#pragma endregion

#pragma region Member Functions

public:
	void Update();

#pragma endregion
};



} // namespace core
} // namespace pad