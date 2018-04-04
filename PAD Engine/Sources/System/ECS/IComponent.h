#pragma once

#include <Utilities/Export.h>
#include <Math/Transform.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class PADObject;

class ENGINE_API IComponent
{
public:
	virtual void Init(PADObject* const _owner)		= 0;
	virtual void Start()							= 0;
	virtual void Update()							= 0;
	virtual void FixedUpdate()						= 0;
	virtual void LateUpdate()						= 0;

	virtual void SetOwner(PADObject* const _owner)	= 0;
	virtual PADObject* const GetOwner() const		= 0;

protected:
	math::Transform*	m_transform;
	PADObject*			m_owner;
};

} // namespace ecs
} // namespace sys
} // namespace pad