#pragma once

#include <list>
#include <Math/Transform.h>

namespace pad	{
namespace core	{

class SceneObject
{
#pragma region Constructor / Destructor

public:
	SceneObject();
	SceneObject(SceneObject* const _parent);

	~SceneObject();

	SceneObject(const SceneObject&)		= delete;
	SceneObject(const SceneObject&&)	= delete;

#pragma endregion

#pragma region Variables

private:
	math::Transform			transform;
	std::list<SceneObject*>	childs;
	SceneObject*			parent;

#pragma endregion

#pragma region Member Functions

public:
	void AddChild(SceneObject* const _child);
	void RemoveChild(SceneObject* const _child);
	void Update();

#pragma endregion

	void SetParent(SceneObject* const _parent);
};

} // namespace core
} // namespace pad