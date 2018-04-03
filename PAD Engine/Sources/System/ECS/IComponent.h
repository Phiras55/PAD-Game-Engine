#pragma once

#include <Utilities/Export.h>
#include <Math/Transform.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API IComponent
{
public:
	virtual void Init()			= 0;
	virtual void Start()		= 0;
	virtual void Update()		= 0;
	virtual void FixedUpdate()	= 0;
	virtual void LateUpdate()	= 0;

protected:
	math::Transform* m_transform;
};

} // namespace ecs
} // namespace sys
} // namespace pad