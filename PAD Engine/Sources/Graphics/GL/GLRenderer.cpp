#include <Graphics/GL/GLRenderer.h>
#include <Logger/SimpleLogger.h>
#include <Utilities/EnumUtils.h>
#include <Graphics/RHI/Shader/AShaderProgram.h>
#include <Graphics/GL/GLVertexBuffer.h>
#include <Graphics/GL/GLVertexArray.h>
#include <Graphics/GL/GLVertexElementBuffer.h>
#include <Graphics/RHI/Shader/ShaderInfos.h>

#include <GL/glew.h>

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

void GLRenderer::ForwardRendering(mod::Mesh* const _mesh, const rhi::RenderSettings* const _settings, const math::Mat4& _vp, const uint32 _meshCount)
{
	if (!_mesh || !_settings)
		return;

	for (uint32 meshIdx = 0; meshIdx < _meshCount; ++meshIdx)
	{
		const mod::Mesh&			currentMesh		= _mesh[meshIdx];
		const rhi::RenderSettings&	currentSettings	= _settings[meshIdx];
		const uint32				shaderCount		= (uint32)currentSettings.programs.size();

		if (shaderCount == 0)
			continue;

		if(currentSettings.isWireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glBindVertexArray(currentMesh.GetVertexArrayID());

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

			glDrawElements(GL_TRIANGLES, currentMesh.GetIndiceCount(), GL_UNSIGNED_INT, nullptr);
		}
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

void GLRenderer::GenerateMesh(mod::Mesh& _m, const mod::MeshData& _md)
{
	gfx::gl::GLVertexArray* vao = new gfx::gl::GLVertexArray();
	vao->GenerateID();
	vao->Bind();

	_m.SetVertexArray(vao);

	gfx::gl::GLVertexBuffer vbo;
	vbo.GenerateID();
	vbo.Bind();
	vbo.BindData(_md.positions, _md.positionCount, 3, static_cast<uint8>(gfx::rhi::shad::AttribLocation::POSITION));

	gfx::gl::GLVertexElementBuffer* ibo = new gfx::gl::GLVertexElementBuffer();
	ibo->GenerateID();
	ibo->Bind();
	ibo->BindData(_md.indices, _md.indiceCount);

	_m.SetVertexElementBuffer(ibo);
}

void GLRenderer::GenerateBuffer(uint32& _id)
{

}

} // namespace gl
} // namespace gfx
} // namespace pad