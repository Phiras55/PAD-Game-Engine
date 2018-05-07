#pragma once
#include <PCH.h>
#include <Graphics/RHI/ATexture.h>

namespace pad	{
namespace gfx	{
namespace mod	{

struct MaterialSettings final
{
	math::Vec4f		m_albedo;
	math::Vec3f		m_ambient;
	math::Vec3f		m_diffuse;
	math::Vec3f		m_specular;
	float			m_shiness;
	rhi::ATexture*	m_albedoMap;
	rhi::ATexture*  m_normalMap;
	std::string		m_name;
};

} // namespace mod
} // namespace gfx
} // namespace pad