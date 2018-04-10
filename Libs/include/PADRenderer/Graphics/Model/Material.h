#pragma once
#include <Common.h>

#include <Math/Vector4.h>

namespace pad	{
namespace gfx	{
namespace mod	{

class Material final
{
public:
	Material();
	~Material();

	Material(const Material&)	= delete;
	Material(Material&&)		= delete;

private:
	math::Vec4f m_color;
	uint32		m_textureID;

public:
	void operator=(const Material&) = delete;
	void operator=(Material&&)		= delete;
};

} // namespace mod
} // namespace gfx
} // namespace pad