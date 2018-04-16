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
	InitWindingOrder(_settings);
}

void GLRenderer::InitMainBuffer(const rhi::ContextSettings& _settings)
{
	if (util::IsFlagSet(_settings.enabledBuffers, gfx::rhi::E_BUFFER_TYPE::DEPTH_BUFFER))
	{
		InitDepthBuffer(_settings);
	}

	if (util::IsFlagSet(_settings.enabledBuffers, gfx::rhi::E_BUFFER_TYPE::STENCIL_BUFFER))
	{
		glEnable(GL_STENCIL_TEST);
		glStencilMask(0x00);
	}
}

void GLRenderer::InitDepthBuffer(const rhi::ContextSettings& _settings)
{
	glEnable(GL_DEPTH_TEST);

	int depthFunction = 0;
	switch (_settings.depthFunc)
	{
	case rhi::E_DEPTH_FUNCTION::ALWAYS:
		depthFunction = GL_ALWAYS;
		break;
	case rhi::E_DEPTH_FUNCTION::EQUAL:
		depthFunction = GL_EQUAL;
		break;
	case rhi::E_DEPTH_FUNCTION::GEQUAL:
		depthFunction = GL_GEQUAL;
		break;
	case rhi::E_DEPTH_FUNCTION::GREATER:
		depthFunction = GL_GREATER;
		break;
	case rhi::E_DEPTH_FUNCTION::LEQUAL:
		depthFunction = GL_LEQUAL;
		break;
	case rhi::E_DEPTH_FUNCTION::LESS:
		depthFunction = GL_LESS;
		break;
	case rhi::E_DEPTH_FUNCTION::NEVER:
		depthFunction = GL_NEVER;
		break;
	case rhi::E_DEPTH_FUNCTION::NOTEQUAL:
		depthFunction = GL_NOTEQUAL;
		break;
	}
	glDepthFunc(depthFunction);
}

void GLRenderer::InitCullFace(const rhi::ContextSettings& _settings)
{
	glEnable(GL_CULL_FACE);

	int cullFace = 0;
	switch (_settings.cullFace)
	{
	case rhi::E_CULL_FACE::BACK:
		cullFace = GL_BACK;
		break;
	case rhi::E_CULL_FACE::FRONT:
		cullFace = GL_FRONT;
		break;
	case rhi::E_CULL_FACE::FRONT_AND_BACK:
		cullFace = GL_FRONT_AND_BACK;
		break;
	}
	glCullFace(cullFace);
}

void GLRenderer::InitWindingOrder(const rhi::ContextSettings& _settings)
{
	int windingOrder = 0;
	switch (_settings.windingOrder)
	{
	case rhi::E_WINDING_ORDER::COUNTER_CLOCKWISE:
		windingOrder = GL_CCW;
		break;
	case rhi::E_WINDING_ORDER::CLOCKWISE:
		windingOrder = GL_CW;
		break;
	}
	glFrontFace(windingOrder);
}

void GLRenderer::InitViewPort(const math::Vec2i& _viewportSize)
{
	glViewport(
		0, 
		0,
		_viewportSize.x,
		_viewportSize.y);
}

void GLRenderer::ForwardRendering(
	rhi::AVertexArray* const _vao,
	rhi::AVertexBuffer* const _ibo,
	const rhi::RenderSettings _setting,
	const math::Mat4& _vp)
{
	if (!_vao || !_ibo)
		return;

	const uint32 shaderCount = (uint32)_setting.programs.size();

	if (shaderCount == 0)
		return;

	glBindVertexArray(_vao->GetID());

	if (_setting.isWireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for (rhi::shad::AShaderProgram* const currentProgram : _setting.programs)
	{
		if (!currentProgram)
		{
			LOG_ERROR_S("The shader is not valid. Try to add one in the RenderSettings.\n");
			continue;
		}

		currentProgram->Use();
		currentProgram->SetUniform("albedo", math::Vec4f(1, 0, 0, 1));
		currentProgram->SetUniform("mvp", _vp * *_setting.modelMatrix);

		glDrawElements(GL_TRIANGLES, _ibo->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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