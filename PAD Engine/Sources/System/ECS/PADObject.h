#pragma once
#include <System/ResourceHandling/ComponentsHandler.h>
#include <Json/Serialization.h>
#include <Utilities/Export.h>
#include <bitset>

namespace pad	{
namespace sys	{
namespace ecs	{

namespace alias	{
	using ChildList = std::list<PADObject*>;
}

#define MAX_COMPONENT_COUNT 20u

class AComponent;

class ENGINE_API PADObject final : public ISerializable
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
	math::Transform						m_transform;
	alias::ChildList					m_childs;
	PADObject*							m_parent;
	bool								m_dontDestroy;
								
	std::string							m_name;
	std::vector<AComponent*>			m_components;
	std::bitset<MAX_COMPONENT_COUNT>	m_hasComponent;
	ecs::ACollider*						m_collider;
	
	static res::ComponentsHandler*		m_componentHandlerHandle;

#pragma endregion

#pragma region Member Functions

public:
	void AddChild(PADObject* const _child);
	void RemoveChild(PADObject* const _child);

	template<typename T, typename ...Targs>
	T* AddComponent(Targs&&... _args)
	{
		AssertIfNotComponent<T>();
		T* comp = nullptr;
		if (!HasComponent<T>())
		{
			comp = m_componentHandlerHandle->CreateComponent<T, Targs...>(std::forward<Targs>(_args)...);
			if (comp)
			{
				if constexpr (std::is_base_of<ACollider, T>::value)
				{
					m_collider = static_cast<ACollider*>(comp);
				}

				comp->SetOwner(this);
				comp->Init();
				comp->Start();
				m_components[comp->GetType()] = comp;
				m_hasComponent[comp->GetType()] = true;
			}
		}
		return comp;
	}

	template<typename T>
	T* GetComponent()
	{
		AssertIfNotComponent<T>();
		T* comp = nullptr;

		if (HasComponent<T>())
		{
			T type;
			comp = static_cast<T*>(m_components[type.GetType()]);
		}

		return comp;
	}

	template<typename T>
	bool HasComponent()
	{
		AssertIfNotComponent<T>();
		T type;
		return m_hasComponent[type.GetType()];
	}

	template<typename T>
	void RemoveComponent()
	{
		AssertIfNotComponent<T>();
		if (HasComponent<T>())
		{
			T comp;
			m_hasComponent[comp.GetType()] = false;
			m_componentHandlerHandle->RemoveComponent<T>(m_components[comp.GetType()]);
			m_components[comp.GetType()] = nullptr;
		}
	}

	template <typename T>
	void AssertIfNotComponent()
	{
		static_assert(std::is_base_of<ecs::AComponent, T>::value, "T needs to be a derived class from AComponent.");
	}

	void Init();
	void Start();
	void Update();
	void FixedUpdate();
	void LateUpdate();

	json Serialize()				override;
	void Deserialize(const json& _j)override;

	AComponent* const AddComponentFromName(const std::string& _name);

#pragma endregion

#pragma region Getter / Setter

public:
	void SetParent(PADObject* const _parent);
	inline PADObject* const GetParent() const			{ return m_parent; }

	inline math::Transform& GetTransform() 				{ return m_transform; }
	inline const math::Transform& GetTransform() const	{ return m_transform; }

	inline void SetName(const std::string _name)		{ m_name = _name; }
	inline const std::string& GetName() const			{ return m_name; }

	inline const alias::ChildList& GetChildren() const	{ return m_childs; }

	inline ACollider* const GetCollider()				{ return m_collider; }

	inline static void SetComponentHandler(res::ComponentsHandler* const _handle) { m_componentHandlerHandle = _handle; }
#pragma endregion
};

} // namespace ecs
} // namespace sys
} // namespace pad