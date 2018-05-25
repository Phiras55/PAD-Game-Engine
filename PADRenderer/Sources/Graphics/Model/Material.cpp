#include <PCH.h>
#include <Graphics/Model/Material.h>

namespace pad	{
namespace gfx	{
namespace mod	{

Material::Material() :
	m_diffuse(1.f, 1.f, 1.f),
	m_shininess(0.f)
{

}

Material::~Material()
{

}

} // namespace mod
} // namespace gfx
} // namespace pad