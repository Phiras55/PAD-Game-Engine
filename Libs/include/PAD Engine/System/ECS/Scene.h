#pragma once
#include <System/ECS/PADObject.h>
#include <Json/Serialization.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class Scene final : public ISerializable
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
	
	json Serialize()				override;
	void Deserialize(const json& j)	override;

public:
	inline PADObject* const GetMasterObject() { return m_masterPADObject; }
};

} // namespace ecs
} // namespace sys
} // namespace pad