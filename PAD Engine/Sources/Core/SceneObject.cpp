#include <Core/SceneObject.h>
#include <algorithm>

namespace pad	{
namespace core	{

SceneObject::SceneObject() :
	parent(nullptr)
{

}

SceneObject::SceneObject(SceneObject* const _parent) :
	parent(_parent)
{

}

SceneObject::~SceneObject()
{
	if (parent)
		parent->RemoveChild(this);

	for (SceneObject* so : childs)
	{
		so->SetParent(nullptr);
		so->~SceneObject();
	}
}

void SceneObject::AddChild(SceneObject* const _child)
{
	if (_child->parent)
		_child->parent->RemoveChild(_child);

	_child->parent = this;
	childs.push_back(_child);
}

void SceneObject::RemoveChild(SceneObject* const _child)
{
	childs.remove(_child);
}

void SceneObject::Update()
{
	transform.SetGlobalTransform(		parent->transform.GetGlobalTransform() 
									*	transform.GetLocalTransform());

	for (SceneObject* so : childs)
		so->Update();
}

void SceneObject::SetParent(SceneObject* const _parent)
{
	if (parent)
		parent->RemoveChild(this);

	parent = _parent;
	_parent->AddChild(this);
}

} // namespace core
} // namespace pad