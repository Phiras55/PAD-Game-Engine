#pragma once

#include <list>
#include <Math/Transform.h>
#include <System/ECS/IComponent.h>
#include <vector>
#include <Utilities/Export.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API PADObject
{
#pragma region Constructor / Destructor

public:
	PADObject();
	PADObject(PADObject* const _parent);

	~PADObject();

	PADObject(const PADObject&)		= delete;
	PADObject(const PADObject&&)	= delete;

#pragma endregion

#pragma region Variables

private:
	math::Transform				m_transform;
	std::list<PADObject*>		m_childs;
	PADObject*					m_parent;
	bool						m_dontDestroy;
								
	std::string					m_name;
	std::list<IComponent*>		m_components;

#pragma endregion

#pragma region Member Functions

public:
	void AddChild(PADObject* const _child);
	void RemoveChild(PADObject* const _child);

	void AddComponent(IComponent* const _component);
	void RemoveComponent(IComponent* const _component);

	void Init();
	void Start();
	void Update();
	void FixedUpdate();
	void LateUpdate();

#pragma endregion

#pragma region MyRegion

	void SetParent(PADObject* const _parent);

	inline math::Transform& GetTransform() 				{ return m_transform; }
	inline const math::Transform& GetTransform() const	{ return m_transform; }

	inline void SetName(const std::string _name)		{ m_name = _name; }
	inline const std::string& GetName() const			{ return m_name; }

#pragma endregion
};

} // namespace ecs
} // namespace sys
} // namespace pad