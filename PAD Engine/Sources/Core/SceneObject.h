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
	SceneObject(SceneObject* const _parent);

	~SceneObject();

	SceneObject(const SceneObject&)		= delete;
	SceneObject(const SceneObject&&)	= delete;

#pragma endregion

#pragma region Variables

private:
	Transform					transform;
	std::vector<SceneObject*>	childs;
	SceneObject*				parent;

	static unsigned int counter;
	unsigned int id;

#pragma endregion

#pragma region Member Functions

public:
	void AddChild(SceneObject* const _child);
	void RemoveChild(SceneObject* const _child);
	void Update(std::string _test);

#pragma endregion

	void SetParent(SceneObject* const _parent);
};

} // namespace core
} // namespace pad