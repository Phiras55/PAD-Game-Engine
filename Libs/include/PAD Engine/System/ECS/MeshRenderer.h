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
	MeshRenderer(math::Transform& _ownerTransform);
	~MeshRenderer();

	MeshRenderer() = delete;

private:
	std::string m_meshName;
	std::string m_materialName;
	gfx::rhi::RenderSettings m_settings;

	static std::vector<MeshRenderer> m_collection;

public:
	void Init(PADObject* const _owner)		override;
	void Start()							override;
	void Update()							override;
	void FixedUpdate()						override;
	void LateUpdate()						override;

	void SetOwner(PADObject* const _owner)	override			{ m_owner = _owner; }
	PADObject* const GetOwner() const		override			{ return m_owner; }

	void SetMeshName(const std::string& _name)					{ m_meshName = _name; }
	const std::string& GetMeshName() const						{ return m_meshName; }

	void SetMaterialName(const std::string& _name)				{ m_materialName = _name; }
	const std::string& GetMaterialName() const					{ return m_materialName; }
		
	inline		 gfx::rhi::RenderSettings& GetSettings()		{ return m_settings; }
	inline const gfx::rhi::RenderSettings& GetSettings() const	{ return m_settings; }

	static const std::vector<MeshRenderer>& GetCollection()		{ return m_collection; }

	static void AddToCollection(const MeshRenderer& _meshRenderer);
};

} // namespace ecs
} // namespace sys
} // namespace pad