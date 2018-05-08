#pragma once

#include <Utilities/Export.h>
#include <Math/Transform.h>
#include <System/ECS/PADObject.h>
#include <Json/Serialization.h>

namespace pad	{
namespace sys	{
namespace ecs	{

enum COMPONENT_TYPE
{
	MESH_RENDERER,
	RIGIDBODY,
	COLLIDER,
	CAMERA,
	SCRIPT
};

class ENGINE_API IComponent : public ISerializable
{
public:
	virtual void Init()								= 0;
	virtual void Start()							= 0;
	virtual void Update()							= 0;
	virtual void FixedUpdate()						= 0;
	virtual void LateUpdate()						= 0;

	virtual void SetOwner(PADObject* const _owner)		= 0;
	virtual PADObject* const GetOwner() const			= 0;

	virtual const COMPONENT_TYPE GetType() const		= 0;

	virtual const math::Transform& GetTransform() const	= 0;
	virtual math::Transform& GetTransform()				= 0;

protected:
	math::Transform		m_transform;
	PADObject*			m_owner;
	COMPONENT_TYPE		m_type;
};

} // namespace ecs
} // namespace sys
} // namespace pad