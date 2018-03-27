#pragma once

#include <list>
#include <Math/Transform.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class PADObject
{
#pragma region Constructor / Destructor

public:
	PADObject();
	PADObject(PADObject* const _parent);

	~PADObject();

	PADObject(const PADObject&)		= delete;
	PADObject(const PADObject&&)	= delete;

#pragma endregion

#pragma region Variables

private:
	math::Transform			transform;
	std::list<PADObject*>	childs;
	PADObject*				parent;
	bool					dontDestroy;

#pragma endregion

#pragma region Member Functions

public:
	void AddChild(PADObject* const _child);
	void RemoveChild(PADObject* const _child);
	void Update();

#pragma endregion


	void SetParent(PADObject* const _parent);
};

} // namespace ecs
} // namespace sys
} // namespace pad