#pragma once

#include <System/ECS/IComponent.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/Model/Material.h>
#include <Graphics/RHI/RenderSettings.h>

#include <Utilities/Export.h>
#include <string>
#include <vector>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API MeshRenderer : public IComponent
{
public:
	MeshRenderer();
	~MeshRenderer();

private:
	std::string m_meshName;
	std::string m_materialName;

	static std::vector<MeshRenderer> m_collection;

public:
	void Init()			override;
	void Start()		override;
	void Update()		override;
	void FixedUpdate()	override;
	void LateUpdate()	override;

	void SetOwner(PADObject* const _owner)	override		{ m_owner = _owner; }
	PADObject* const GetOwner() const		override		{ return m_owner; }

	virtual const COMPONENT_TYPE GetType() const override	{ return m_type; }

	void SetMeshName(const std::string& _name)				{ m_meshName = _name; }
	const std::string& GetMeshName() const					{ return m_meshName; }

	void SetMaterialName(const std::string& _name)			{ m_materialName = _name; }
	const std::string& GetMaterialName() const				{ return m_materialName; }

	static const std::vector<MeshRenderer>& GetCollection() { return m_collection; }
};

} // namespace ecs
} // namespace sys
} // namespace pad