#pragma once
#include <Common.h>

#include <Math/Vector4.h>
#include <Graphics/RHI/ATexture.h>

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
	math::Vec4f		m_albedo;
	rhi::ATexture*	m_texture;

public:
	inline rhi::ATexture* const GetTexture() const	{ return m_texture; }
	inline rhi::ATexture*		GetTexture()		{ return m_texture; }
	inline const math::Vec4f&	GetAlbedo() const	{ return m_albedo; }
	inline math::Vec4f&			GetAlbedo() 		{ return m_albedo; } 

public:
	void operator=(const Material&) = delete;
	void operator=(Material&&)		= delete;
};

} // namespace mod
} // namespace gfx
} // namespace pad