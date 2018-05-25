#pragma once
#include <PCH.h>
#include <Graphics/RHI/ATexture.h>

namespace pad	{
namespace gfx	{
namespace mod	{

class Material final
{
public:
	Material();
	~Material();

//	Material(const Material&)	= delete;
//	Material(Material&&)		= delete;
	
private:
	math::Vec4f		m_albedo;
	math::Vec3f		m_ambient;
	math::Vec3f		m_diffuse;
	math::Vec3f		m_specular;
	float			m_shininess;
	std::string		m_albedoMapName;
	std::string		m_normalMapName;
	std::string		m_name;

public:
	inline const std::string&	GetAlbedoMapName()	const	{ return m_albedoMapName; }
	inline const std::string&	GetNormalMapName()	const	{ return m_normalMapName; }
	inline const math::Vec4f&	GetAlbedo()			const	{ return m_albedo; }
	inline const math::Vec3f&	GetAmbient()		const	{ return m_ambient; }
	inline const math::Vec3f&	GetDiffuse()		const	{ return m_diffuse; }
	inline const math::Vec3f&	GetSpecular()		const	{ return m_specular; }
	inline const float&			GetShininess()		const	{ return m_shininess; }
	inline const std::string&	GetName()			const	{ return m_name; }

	inline void SetAlbedoMapName(const std::string& _n)		{ m_albedoMapName = _n; }
	inline void SetNormalMapName(const std::string& _n)		{ m_normalMapName = _n; }
	inline void SetAlbedo(const math::Vec4f& _albedo)		{ m_albedo = _albedo; }
	inline void SetAmbient(const math::Vec3f& _ambient)		{ m_ambient = _ambient; }
	inline void SetDiffuse(const math::Vec3f& _diffuse)		{ m_diffuse = _diffuse; }
	inline void SetSpecular(const math::Vec3f& _specular)	{ m_specular = _specular; }
	inline void SetShininess(const float _shininess)		{ m_shininess = _shininess; }
	inline void SetName(const std::string& _name)			{ m_name = _name; }

	inline void SetAlbedo(const math::Vec3f& _color, const float _w = 1.f) { m_albedo.x = _color.x; m_albedo.y = _color.y; m_albedo.z = _color.z; m_albedo.w = _w; }
	inline void SetAlbedo(const float _x, const float _y, const float _z, const float _w = 1.f) { m_albedo.x = _x; m_albedo.y = _y; m_albedo.z = _z; m_albedo.w = _w; }

public:
//	void operator=(const Material&) = delete;
//	void operator=(Material&&)		= delete;
};

} // namespace mod
} // namespace gfx
} // namespace pad