#include <System/ECS/PADObject.h>
#include <algorithm>

namespace pad	{
namespace sys	{
namespace ecs	{

PADObject::PADObject() :
	parent(nullptr),
	dontDestroy(false)
{

}

PADObject::PADObject(PADObject* const _parent) :
	parent(_parent)
{

}

PADObject::~PADObject()
{
	if (parent)
		parent->RemoveChild(this);

	for (PADObject* so : childs)
	{
		so->SetParent(nullptr);
		so->~PADObject();
	}
}

void PADObject::AddChild(PADObject* const _child)
{
	if (_child->parent)
		_child->parent->RemoveChild(_child);

	_child->parent = this;
	childs.push_back(_child);
}

void PADObject::RemoveChild(PADObject* const _child)
{
	childs.remove(_child);
}

void PADObject::Update()
{
	transform.SetGlobalTransform(		parent->transform.GetGlobalTransform() 
									*	transform.GetLocalTransform());

	for (PADObject* so : childs)
		so->Update();
}

void PADObject::SetParent(PADObject* const _parent)
{
	if (parent)
		parent->RemoveChild(this);

	parent = _parent;
	_parent->AddChild(this);
}

} // namespace ecs
} // namespace sys
} // namespace pad