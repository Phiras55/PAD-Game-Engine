#pragma once
#include <Utilities/Export.h>
#include <Math/Transform.h>
#include <Json/Serialization.h>
#include <Utilities/UniqueIDs.h>

namespace pad	{
namespace sys	{
namespace ecs	{

#define INVALID_COMPONENT_ID -1

class PADObject;

namespace alias	{
	using ComponentID = uint8;
}

class ENGINE_API AComponent : public ISerializable
{
public:
	AComponent() : m_owner(nullptr) {}
	virtual ~AComponent() = default;

public:
	virtual void Init()								= 0;
	virtual void Start()							= 0;
	virtual void Update()							= 0;
	virtual void FixedUpdate()						= 0;
	virtual void LateUpdate()						= 0;

	virtual const alias::ComponentID GetType() const = 0;

	inline PADObject* const GetOwner()							{ return m_owner; }
	inline void				SetOwner(PADObject* const _owner)	{ m_owner = _owner; }

protected:
	PADObject* m_owner;
};

} // namespace ecs
} // namespace sys
} // namespace pad