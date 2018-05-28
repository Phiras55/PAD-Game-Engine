#pragma once
#include <System/ECS/AComponent.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ALight : public AComponent
{
public:
	ALight() : m_color(0.f, 0.f, 0.f), m_intensity(1.f) {}
	~ALight() = default;

protected:
	math::Vec3f m_color;
	float32		m_intensity;

public:
	inline const math::Vec3f&	GetColor() const		{ return m_color; }
	inline const float&			GetIntensity() const	{ return m_intensity; }

	inline void SetColor(const math::Vec3f& _color)		{ m_color = _color; }
	inline void SetIntensity(const float& _intensity)	{ m_intensity = _intensity; }
};

} // namespace ecs
} // namespace sys
} // namespace pad