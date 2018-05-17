#pragma once

#include <Math/Vector4.h>
#include <string>

namespace pad	{
namespace gfx	{
namespace mod	{

struct MaterialData
{
	math::Vec4f		m_albedo;
	math::Vec3f		m_ambient;
	math::Vec3f		m_diffuse;
	math::Vec3f		m_specular;
	float			m_shiness;
	std::string		m_name;
};

} // namespace mod
} // namespace gfx
} // namespace pad