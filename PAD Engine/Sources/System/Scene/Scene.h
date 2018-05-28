#pragma once
#include <System/ECS/PerspectiveCamera.h>
#include <System/ECS/DirectionalLight.h>
#include <System/ECS/PADObject.h>
#include <Json/Serialization.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class Scene final
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
	math::Vec3f			m_lightRotation;
	bool				m_isLightRotating;

public:
	void Init();
	void Start();
	void Update();
	void FixedUpdate();
	void LateUpdate();
	void AddPADObject(PADObject* _PADObject);
	void ToggleDirectionalLightRotation();
	void SetLightRotation(const math::Vec3f& _rotation);

	PADObject*	GetPADObject(const std::string& _name, PADObject* const _rootSearch = nullptr);
	PADObject*	CreatePADObject(const std::string& _name, PADObject* const _parent = nullptr);
	void		DeletePADObject(PADObject* const _object);
	
	void Serialize(const std::string& _savePath);
	void Deserialize(const std::string& _savePath);

private:
	PADObject* FindPADObject(const std::string& _name, PADObject* const _rootSearch = nullptr);

public:
	inline PADObject* const			GetMasterObject()		{ return m_masterPADObject; }
	inline PerspectiveCamera* const	GetMainCamera()			{ return m_mainCamera; }
	inline DirectionalLight* const	GetDirectionalLight()	{ return m_directionalLight; }
};

} // namespace ecs
} // namespace sys
} // namespace pad