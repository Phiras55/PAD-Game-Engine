#pragma once

#include <vector>
#include <Core/PADObject.h>

namespace pad	{
namespace core	{

class Scene final
{
#pragma region Constructor / Destructor

public:
	Scene();
	~Scene();

	Scene(const Scene&)		= delete;
	Scene(const Scene&&)	= delete;

#pragma endregion


public:
	PADObject* masterPADObject;

public:
	void Update();
	void AddPADObject(PADObject* _PADObject);
//	void Render();
};

} // namespace core
} // namespace pad