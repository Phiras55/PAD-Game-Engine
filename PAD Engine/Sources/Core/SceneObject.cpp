#include "SceneObject.h"

pad::core::SceneObject::SceneObject()
{

}

void pad::core::SceneObject::Update()
{
	for (int i = 0; i < children.size(); ++i)
	{
		children[i]->Update();
	}
}