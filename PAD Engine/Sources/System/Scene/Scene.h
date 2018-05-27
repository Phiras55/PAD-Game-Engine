#pragma once
#include <System/ECS/PerspectiveCamera.h>
#include <System/ECS/DirectionalLight.h>
#include <System/ECS/PADObject.h>
#include <Json/Serialization.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class Scene final : public ISerializable
{
public:
	Scene();
	~Scene();

	Scene(const Scene&)		= delete;
	Scene(const Scene&&)	= delete;

private:
	PADObject*			m_masterPADObject;
	PerspectiveCamera*	m_mainCamera;
	DirectionalLight*	m_directionalLight;

public:
	void Init();
	void Start();
	void Update();
	void FixedUpdate();
	void LateUpdate();
	void AddPADObject(PADObject* _PADObject);

	PADObject*	GetPADObject(const std::string& _name, PADObject* const _rootSearch = nullptr);
	PADObject*	CreatePADObject(const std::string& _name, PADObject* const _parent = nullptr);
	void		DeletePADObject(const std::string& _name, PADObject* const _rootSearch = nullptr);
	
	json Serialize()				override;
	void Deserialize(const json& j)	override;

private:
	PADObject* FindPADObject(const std::string& _name, PADObject* const _rootSearch = nullptr);

public:
	inline PADObject* const		GetMasterObject()		{ return m_masterPADObject; }
	inline PerspectiveCamera*	GetMainCamera()			{ return m_mainCamera; }
	inline DirectionalLight*	GetDirectionalLight()	{ return m_directionalLight; }
};

} // namespace ecs
} // namespace sys
} // namespace pad