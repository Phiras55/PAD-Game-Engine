#pragma once

#include <vector>
#include <System/ECS/PADObject.h>

namespace pad	{
namespace sys	{
namespace ecs	{

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

} // namespace ecs
} // namespace sys
} // namespace pad