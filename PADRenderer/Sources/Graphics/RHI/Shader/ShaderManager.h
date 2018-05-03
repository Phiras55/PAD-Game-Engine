#pragma once

namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

class ShaderManager	final
{
public:
	ShaderManager();
	~ShaderManager();

	ShaderManager(const ShaderManager&)		= delete;
	ShaderManager(ShaderManager&&)			= delete;

private:


public:
	void operator=(const ShaderManager&)	= delete;
	void operator=(ShaderManager&&)			= delete;
};

} // namespace shad
} // namespace rhi
} // namespace gfx
} // namespace pad