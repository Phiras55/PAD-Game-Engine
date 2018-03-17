#include <Core/SceneObject.h>
#include <algorithm>

namespace pad	{
namespace core	{

unsigned int SceneObject::counter = 0;

SceneObject::SceneObject() :
	parent(nullptr)
{
	id = counter;
	counter++;
}

SceneObject::SceneObject(SceneObject* const _parent) :
	parent(_parent)
{
	id = counter;
	counter++;
}

SceneObject::~SceneObject()
{
	if (parent)
		parent->RemoveChild(this);
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
	// besoin de discuter pour optimisation

	childs.erase(std::remove(childs.begin(), childs.end(), _child), childs.end());

	//Alternative approach

	//auto it = std::find(childs.begin(), childs.end(), _child);
	//if (it != childs.end())
	//{
	//	std::swap(*it, childs.back());
	//	childs.pop_back();
	//}
}

void SceneObject::Update(std::string _test)
{
	std::cout << _test.c_str() << id << "\n";
	_test += "  ";

	//	transform = parent->transform * transform;

	for (int i = 0; i < childs.size(); ++i)
	{
		childs[i]->Update(_test);
	}
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