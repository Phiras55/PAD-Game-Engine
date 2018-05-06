#include <PCH.h>
#include <Graphics/Model/Material.h>

namespace pad	{
namespace gfx	{
namespace mod	{

Material::Material() :
	m_albedoMap(nullptr),
	m_normalMap(nullptr),
	m_shiness(0.f)
{

}

Material::~Material()
{

}

} // namespace mod
} // namespace gfx
} // namespace pad