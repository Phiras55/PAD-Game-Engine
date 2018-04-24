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


private:
	PADObject*		m_masterPADObject;

public:
	void Init();
	void Start();
	void Update();
	void FixedUpdate();
	void LateUpdate();
	void AddPADObject(PADObject* _PADObject);

public:
	inline PADObject* const GetMasterObject() { return m_masterPADObject; }
};

} // namespace ecs
} // namespace sys
} // namespace pad