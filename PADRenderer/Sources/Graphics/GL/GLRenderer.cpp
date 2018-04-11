#include <Graphics/GL/GLRenderer.h>
#include <Logger/SimpleLogger.h>
#include <Utilities/EnumUtils.h>
#include <Graphics/RHI/Shader/AShaderProgram.h>
#include <Graphics/GL/GLVertexBuffer.h>
#include <Graphics/GL/GLVertexArray.h>
#include <Graphics/GL/GLVertexElementBuffer.h>
#include <Graphics/RHI/Shader/ShaderInfos.h>

#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

namespace pad	{
namespace gfx	{
namespace gl	{

GLRenderer::GLRenderer()
{

}

void GLRenderer::Init(const rhi::ContextSettings& _settings)
{
	InitContext(_settings);
	InitViewPort(_settings.viewportSize);
}

void GLRenderer::InitContext(const rhi::ContextSettings& _settings)
{
	if (glewInit() != GLEW_OK)
	{
		LOG_FATAL_S("Could not init glew!\n");
		return;
	}

	glClearColor(
		_settings.clearColor.r,
		_settings.clearColor.g,
		_settings.clearColor.b,
		_settings.clearColor.a);

	glewExperimental = true;

	InitMainBuffer(_settings);
	InitCullFace(_settings);
}

void GLRenderer::InitMainBuffer(const rhi::ContextSettings& _settings)
{
	if (util::IsFlagSet(_settings.enabledBuffers, gfx::rhi::E_BUFFER_TYPE::DEPTH_BUFFER))
	{
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
	}

	if (util::IsFlagSet(_settings.enabledBuffers, gfx::rhi::E_BUFFER_TYPE::STENCIL_BUFFER))
	{
		glEnable(GL_STENCIL_TEST);
		glStencilMask(0x00);
	}
}

void GLRenderer::InitCullFace(const rhi::ContextSettings& _settings)
{
	glEnable(GL_CULL_FACE);

	_settings.areTrianglesCounterClockwise ?
		glCullFace(GL_BACK) :
		glCullFace(GL_FRONT);
}

void GLRenderer::InitViewPort(const math::Vec2i& _viewportSize)
{
	glViewport(
		0, 
		0,
		_viewportSize.x,
		_viewportSize.y);
}

void GLRenderer::ForwardRendering(rhi::AVertexArray* const* const _vaos, rhi::AVertexBuffer* const* const _ibos, const rhi::RenderSettings* const _settings, const math::Mat4& _vp, const uint32 _meshCount)
{
	if (!_vaos || !_ibos || !_settings)
		return;

	for (uint32 meshIdx = 0; meshIdx < _meshCount; ++meshIdx)
	{
		const rhi::AVertexArray*	currentVAO		= _vaos[meshIdx];
		const rhi::AVertexBuffer*	currentIBO		= _ibos[meshIdx];
		const rhi::RenderSettings&	currentSettings	= _settings[meshIdx];
		const uint32				shaderCount		= (uint32)currentSettings.programs.size();

		if (shaderCount == 0 || !currentVAO || !currentIBO)
			continue;

		glBindVertexArray(currentVAO->GetID());

		for (rhi::shad::AShaderProgram* const currentProgram : currentSettings.programs)
		{
			if (!currentProgram)
			{
				LOG_ERROR_S("The shader is not valid. Try to add one in the RenderSettings.\n");
				continue;
			}

			currentProgram->Use();
			currentProgram->SetUniform("albedo", math::Vec4f(1, 0, 0, 1));
			currentProgram->SetUniform("mvp", _vp * *currentSettings.modelMatrix);

			glDrawElements(GL_TRIANGLES, currentIBO->GetCount(), GL_UNSIGNED_INT, nullptr);
		}
	}
}

void GLRenderer::ClearBuffer()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GLRenderer::ResizeViewport(const uint32 _w, const uint32 _h)
{
	glViewport(0, 0, _w, _h);
	m_viewportSize.x = _w;
	m_viewportSize.y = _h;
}

void GLRenderer::GenerateMesh(const mod::MeshData& _md, rhi::AVertexArray* _vao, rhi::AVertexBuffer* _ibo)
{
	if (!_vao || !_ibo)
		return;

	_vao->GenerateID();
	_vao->Bind();

	gfx::gl::GLVertexBuffer vbo;
	vbo.GenerateID();
	vbo.Bind();
	vbo.BindData(_md.positions, _md.positionCount, 3, static_cast<uint8>(gfx::rhi::shad::AttribLocation::POSITION));

	_ibo->GenerateID();
	_ibo->Bind();
	_ibo->BindData(_md.indices, _md.indiceCount);
}

void GLRenderer::GenerateTexture(uint32& _textureID, const std::string& _path)
{
	int width, height, nrChannels;
	unsigned char *data = stbi_load(_path.c_str(), &width, &height, &nrChannels, 0);
}

void GLRenderer::GenerateBuffer(uint32& _id)
{

}

void GLRenderer::SetCustomUniforms(rhi::shad::AShaderProgram* const _program, const rhi::RenderSettings& _settings)
{
	for (const auto& it : _settings.customUniforms)
	{
		_program->SetCustomUniform(it.first, it.second);
	}
}

} // namespace gl
} // namespace gfx
} // namespace pad