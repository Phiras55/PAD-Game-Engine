#pragma once
#include <Common.h>
#include <Graphics/RHI/AVertexArray.h>
#include <Graphics/RHI/TextureParameters.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

class ATexture : public AVertexArray
{
public:
	virtual ~ATexture() = default;

protected:
	std::string m_name;

public:
	virtual void GenerateTexture(
		const int32 _w, 
		const int32 _h, 
		uchar* const _data, 
		const TextureParameters& _param) = 0;

public:
	inline const std::string& GetName()	const { return m_name; }
	inline void SetName(const std::string& _name) { m_name = _name; }
};

} // namespace rhi
} // namespace gfx
} // namespace pad