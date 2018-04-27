#pragma once
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
	rhi::ATexture*	m_albedoMap;
	rhi::ATexture*  m_normalMap;

public:
	inline rhi::ATexture* const GetAlbedoMap() const	{ return m_albedoMap; }
	inline rhi::ATexture*		GetAlbedoMap()			{ return m_albedoMap; }
	inline rhi::ATexture* const GetNormalMap() const	{ return m_normalMap; }
	inline rhi::ATexture*		GetNormalMap()			{ return m_normalMap; }
	inline const math::Vec4f&	GetAlbedo() const		{ return m_albedo; }
	inline math::Vec4f&			GetAlbedo() 			{ return m_albedo; } 

	inline void SetAlbedo(const math::Vec4f& _color) { m_albedo = _color; }
	inline void SetAlbedo(const math::Vec3f& _color, const float _w = 1.f)						{ m_albedo.x = _color.x; m_albedo.y = _color.y; m_albedo.z = _color.z; m_albedo.w = _w; }
	inline void SetAlbedo(const float _x, const float _y, const float _z, const float _w = 1.f) { m_albedo.x = _x; m_albedo.y = _y; m_albedo.z = _z; m_albedo.w = _w; }
	inline void SetAlbedoMap(rhi::ATexture* const _t) { m_albedoMap = _t; }
	inline void SetNormalMap(rhi::ATexture* const _t) { m_normalMap = _t; }


public:
	void operator=(const Material&) = delete;
	void operator=(Material&&)		= delete;
};

} // namespace mod
} // namespace gfx
} // namespace pad