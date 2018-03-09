#include <Graphics/Renderer.h>

#include <GL/glew.h>

namespace pad
{
namespace gfx
{

	Renderer::Renderer()
	{

	}

	void Renderer::StopModule()
	{

	}

	void Renderer::StartModule()
	{

	}

	void Renderer::Init(const RenderSettings& _settings)
	{
		InitContext(_settings.clearColor);
		InitViewPort(_settings.viewportSize);
	}

	void Renderer::InitContext(const math::Vec4f& _clearColor)
	{
		if (glewInit() != GLEW_OK)
		{
			// TODO : Error message
			return;
		}

		glClearColor(
			_clearColor.r,
			_clearColor.g,
			_clearColor.b,
			_clearColor.a);

		glewExperimental = true;

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glDepthFunc(GL_LESS);
	}

	void Renderer::InitViewPort(const math::Vec2i& _viewportSize)
	{
		glViewport(
			0, 
			0,
			_viewportSize.x,
			_viewportSize.y);
	}

	void Renderer::Draw()
	{

	}

	void Renderer::ClearBuffer()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::LoadGeometry(Mesh& mesh, const MeshData& data)
	{
		uint32& vao = mesh.GetVAO();
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		BindBuffer(data.positions, data.positionCount, 3, E_VERTEX_ATTRIB_LOCATION::POSITION);
		BindBuffer(data.uvs, data.uvCount, 2, E_VERTEX_ATTRIB_LOCATION::UV);
		BindBuffer(data.normals, data.normalCount, 3, E_VERTEX_ATTRIB_LOCATION::NORMAL);

		if (data.indices)
		{
			uint32 buffer;
			glGenBuffers(1, &buffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER,
				data.indiceCount * sizeof(*data.indices),
				&data.indices, GL_STATIC_DRAW);
			mesh.SetIndiceCount(data.indiceCount);
		}
	}

	void Renderer::BindBuffer(float* const _data, const uint32 _dataSize, const int32 _vertexElementCount, const E_VERTEX_ATTRIB_LOCATION _location)
	{
		if (_data)
		{
			uint32 buffer;
			uint32 location = static_cast<uint32>(_location);

			glGenBuffers(1, &buffer);
			glBindBuffer(GL_ARRAY_BUFFER, buffer);
			glEnableVertexAttribArray(location);
			glVertexAttribPointer(location, _vertexElementCount, GL_FLOAT, GL_FALSE, 0, nullptr);
			glBufferData(GL_ARRAY_BUFFER,
				_dataSize * sizeof(*_data),
				_data,
				GL_STATIC_DRAW);
		}
	}

} // namespace gfx
} // namespace pad