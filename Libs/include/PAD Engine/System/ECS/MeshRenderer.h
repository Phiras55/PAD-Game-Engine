#pragma once

#include <System/ECS/AComponent.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/Model/Material.h>
#include <Graphics/RHI/RenderSettings.h>

#include <Utilities/Export.h>
#include <string>
#include <vector>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API MeshRenderer : public AComponent
{
public:
	MeshRenderer();
	MeshRenderer(const MeshRenderer& _other);
	MeshRenderer(const std::string& _meshName, const std::string& _materialName);
	~MeshRenderer();

protected:
	std::string					m_meshName;
	std::string					m_materialName;
	gfx::rhi::RenderSettings	m_settings;

	static alias::ComponentID	m_id;
	const std::string			m_name = "MeshRenderer";

public:
	void Init()								override;
	void Start()							override;
	void Update()							override;
	void FixedUpdate()						override;
	void LateUpdate()						override;

	json Serialize()						override;
	void Deserialize(const json& j)			override;

	void SetMeshName(const std::string& _name)					{ m_meshName = _name; }
	const std::string& GetMeshName() const						{ return m_meshName; }

	void SetMaterialName(const std::string& _name)				{ m_materialName = _name; }
	const std::string& GetMaterialName() const					{ return m_materialName; }
		
	inline		 gfx::rhi::RenderSettings& GetSettings()		{ return m_settings; }
	inline const gfx::rhi::RenderSettings& GetSettings() const	{ return m_settings; }

	const alias::ComponentID GetType() const override
	{
		return m_id;
	}

	inline const std::string& GetName() override { return m_name; }

public:
	void operator=(const MeshRenderer& _other);
};

} // namespace ecs
} // namespace sys
} // namespace pad