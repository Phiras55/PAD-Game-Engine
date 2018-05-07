#pragma once
#include <Graphics/RHI/Shader/AShaderProgram.h>

namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

class AShaderManager
{
public:
	AShaderManager() = default;
	virtual ~AShaderManager()
	{
		for (auto& it : m_shaders)
		{
			delete it.second;
		}
		m_shaders.clear();
	}

	AShaderManager(const AShaderManager&)		= delete;
	AShaderManager(AShaderManager&&)			= delete;

protected:
	std::unordered_map<std::string, rhi::shad::AShaderProgram*> m_shaders;

public:
	virtual bool LoadShaders(const std::string& _vertPath, const std::string& _fragPath, const std::string& _name) = 0;
	virtual rhi::shad::AShaderProgram* const GetShader(const std::string& _name) = 0;

public:
	void operator=(const AShaderManager&)		= delete;
	void operator=(AShaderManager&&)			= delete;
};

} // namespace shad
} // namespace rhi
} // namespace gfx
} // namespace pad