#include <PCH.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#include <Utilities/EnumUtils.h>
#include <Graphics/GL/GLRenderer.h>
#include <Graphics/GL/GLVertexArray.h>
#include <Graphics/GL/GLVertexBuffer.h>
#include <Graphics/RHI/Shader/ShaderInfos.h>
#include <Graphics/GL/GLVertexElementBuffer.h>
#include <Graphics/GL/GLUniformBufferObject.h>
#include <Graphics/GL/Shader/GLShaderManager.h>

namespace pad	{
namespace gfx	{
namespace gl	{

GLRenderer::GLRenderer()
{
	m_shaderManager = new gl::shad::GLShaderManager();
}

GLRenderer::~GLRenderer()
{
	for (auto& ubo : m_uniformBufferObjects)
		delete ubo.second;
	m_uniformBufferObjects.clear();

	delete m_shaderManager;
}

void GLRenderer::Init(const rhi::ContextSettings& _settings)
{
	InitContext(_settings);
	InitViewPort(_settings.viewportSize);
	InitShaders();
}

void GLRenderer::InitShaders()
{
	LoadShaders("Resources/Shaders/basicPositions.vert", "Resources/Shaders/basicColors.frag", "Default");
	LoadShaders("Resources/Shaders/animPositions.vert", "Resources/Shaders/basicColors.frag", "DefaultAnim");
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
	InitDefaultUniformBuffers();
	InitBlendFunction();
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

void GLRenderer::InitBlendFunction()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
	const rhi::RenderSettings _setting)
{
	rhi::shad::AShaderProgram* const currentShader = m_shaderManager->GetShader(_setting.programHandle);

	if (!_vao || !_ibo || !currentShader)
		return;

	_vao->Bind();
	_ibo->Bind();

	if (_setting.isWireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (!currentShader)
		return;

	currentShader->Use();
	currentShader->SetUniform("model", *_setting.modelMatrix);
	SetCustomUniforms(currentShader, _setting);

	glDrawElements(GL_TRIANGLES, _ibo->GetCount(), GL_UNSIGNED_INT, (void*)0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	_ibo->Unbind();
	_vao->Unbind();
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
	vbo.Unbind();

	gfx::gl::GLVertexBuffer ubo;
	ubo.GenerateID();
	ubo.Bind();
	ubo.BindData(_md.uvs, _md.uvCount, 2, static_cast<uint8>(gfx::rhi::shad::AttribLocation::UV));
	ubo.Unbind();

	gfx::gl::GLVertexBuffer nbo;
	nbo.GenerateID();
	nbo.Bind();
	nbo.BindData(_md.normals, _md.normalCount, 3, static_cast<uint8>(gfx::rhi::shad::AttribLocation::NORMAL));
	nbo.Unbind();

	gfx::gl::GLVertexBuffer wbo;
	wbo.GenerateID();
	wbo.Bind();
	wbo.BindData(_md.boneWeight, _md.boneWeightCount, 4, static_cast<uint8>(gfx::rhi::shad::AttribLocation::BONE_WEIGHT));
	wbo.Unbind();

	gfx::gl::GLVertexBuffer bbo;
	bbo.GenerateID();
	bbo.Bind();
	bbo.BindData(_md.boneIndex, _md.boneIndexCount, 4, static_cast<uint8>(gfx::rhi::shad::AttribLocation::BONE_INDICE));
	bbo.Unbind();

	_ibo->GenerateID();
	_ibo->Bind();
	_ibo->BindData(_md.indices, _md.indiceCount);
	_ibo->Unbind();

	_vao->Unbind();
}

void GLRenderer::GenerateTexture(rhi::ATexture* const _t, const std::string& _path, const rhi::TextureParameters& _param)
{
	int width, height, nrChannels, channel;
	unsigned char* data = nullptr;

	stbi_set_flip_vertically_on_load(_param.flipY);

	channel = _param.channelType == rhi::ChannelType::RGB ? STBI_rgb : STBI_rgb_alpha;
	data = stbi_load(_path.c_str(), &width, &height, &nrChannels, channel);

	if (data)
	{
		_t->GenerateID();
		_t->Bind();
		_t->GenerateTexture(width, height, data, _param);
		_t->Unbind();
	}
	else
	{
		LOG_ERROR("Could not load the texture at path: %%\n", _path);
	}

	stbi_image_free(data);
}

void GLRenderer::SetCustomUniforms(rhi::shad::AShaderProgram* const _program, const rhi::RenderSettings& _settings)
{
	for (const auto& it : _settings.customUniforms)
	{
		_program->SetCustomUniform(it.first, it.second);
	}
}

void GLRenderer::InitDefaultUniformBuffers()
{
	rhi::UniformBufferSettings cameraSettings;
	cameraSettings.name				= "CameraSettings";
	cameraSettings.dataSize			= 96;
	cameraSettings.bindingPointID	= 0;

	CreateUniformBuffer(cameraSettings);
	BindBufferToBindingPoint(cameraSettings);
}

void GLRenderer::CreateUniformBuffer(const rhi::UniformBufferSettings& _settings)
{
	GLUniformBufferObject* buffer = new GLUniformBufferObject();
	buffer->GenerateID();
	buffer->InitializeBufferData(_settings.dataSize);
	m_uniformBufferObjects[_settings.name] = buffer;
}

void GLRenderer::BindBufferToBindingPoint(const rhi::UniformBufferSettings& _settings)
{
	rhi::AUniformBufferObject* buffer = GetUniformBufferObject(_settings.name);
	if (!buffer)
		return;

	buffer->Bind();
	glBindBufferRange(GL_UNIFORM_BUFFER, _settings.bindingPointID, buffer->GetID(), 0, _settings.dataSize);
	buffer->Unbind();
}

void GLRenderer::SetUniformBufferData(const std::string& _bufferName, const void* const _data, const int _dataSize, const int _offset)
{
	if (m_uniformBufferObjects.find(_bufferName) != m_uniformBufferObjects.end())
		m_uniformBufferObjects[_bufferName]->BindData(_dataSize, _offset, _data);
}

void GLRenderer::SetCameraUniformBufferData(
	const math::Vec3f& _position,
	const math::Vec3f& _direction,
	const math::Mat4& _vp)
{
	SetUniformBufferData("CameraSettings", &_position, 16, 0);
	SetUniformBufferData("CameraSettings", &_direction, 16, 16);
	SetUniformBufferData("CameraSettings", &(_vp.data[0]), 64, 32);
}

void GLRenderer::SetLightsUniformBufferData(
	math::Vec4f* const _positions,
	math::Vec4f* const _directions,
	const uint8 _count)
{
}

rhi::AUniformBufferObject* const GLRenderer::GetUniformBufferObject(const std::string& _name)
{
	if (m_uniformBufferObjects.find(_name) != m_uniformBufferObjects.end())
		return m_uniformBufferObjects[_name];
	return nullptr;
}

bool GLRenderer::LoadShaders(const std::string& _vPath, const std::string& _fPath, const std::string& _name)
{
	return m_shaderManager->LoadShaders(_vPath, _fPath, _name);
}

} // namespace gl
} // namespace gfx
} // namespace pad