#include <iostream>

#include <Math/Matrix4x4.h>
#include <Core/EngineDLL.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <Graphics/GL/Shader/GLFragmentShader.h>
#include <Graphics/PerspectiveCamera.h>

int main()
{
	pad::CreateEngine();
	pad::InitEngine();

	// Will be read from a config file
	pad::sys::WindowSettings winSettings;

	winSettings.title = "This is a SDL Window.";
	winSettings.position.x = 400u;
	winSettings.position.y = 200u;
	winSettings.size.x = 1600u;
	winSettings.size.y = 900u;
	winSettings.isFullscreen = false;
	winSettings.windowType = pad::sys::E_WINDOW_TYPE::ENGINE;

	// Will be read from a config file
	pad::gfx::rhi::ContextSettings renderSettings;

	renderSettings.viewportSize.x = winSettings.size.x;
	renderSettings.viewportSize.y = winSettings.size.y;
	renderSettings.clearColor.r = 0.3f;
	renderSettings.clearColor.g = 0.3f;
	renderSettings.clearColor.b = 0.3f;
	renderSettings.clearColor.a = 1.0f;

	renderSettings.enabledBuffers = pad::gfx::rhi::BufferType::ALL;

	pad::InitWindow(winSettings);
	pad::InitRenderer(renderSettings);

	pad::gfx::mod::Mesh m;
	pad::gfx::mod::MeshData md;
	pad::gfx::rhi::RenderSettings r;

	pad::gfx::gl::shad::GLShaderProgram		program;
	pad::gfx::gl::shad::GLFragmentShader	fragShader;
	pad::gfx::gl::shad::GLVertexShader		vertShader;

	pad::gfx::rhi::shad::AShaderProgram* programs[] = { &program };

	vertShader.LoadShader("../Resources/Shaders/basicPositions.vert");
	fragShader.LoadShader("../Resources/Shaders/basicColors.frag");

	program.SetVertexShader(&vertShader);
	program.SetFragmentShader(&fragShader);
	program.CompileProgram();
	
	r.programs		= programs;
	r.programCount	= 1;

	md.positions = new float[24]{
		-0.5, -0.5,  0.5,
		 0.5, -0.5,  0.5,
		-0.5,  0.5,  0.5,
		 0.5,  0.5, -0.5,
		-0.5, -0.5, -0.5,
		-0.5,  0.5, -0.5,
		 0.5, -0.5, -0.5,
		 0.5,  0.5,  0.5
	};

	md.positionCount = 24;

	md.indices = new pad::uint32[36]{
		0, 1, 2,
		3, 4, 5,
		4, 3, 6,
		7, 2, 1,

		4, 6, 1,
		4, 2, 5,
		7, 1, 6,
		5, 2, 7,

		4, 0, 2,
		6, 3, 7,
		1, 0, 4,
		7, 3, 5
	};

	md.indiceCount = 36;

	pad::DebugGenerateMesh(m, md);

	pad::gfx::PerspectiveCamera c;

	while (pad::IsWindowOpen())
	{
		pad::PollEvents();

		pad::ClearBuffer();

		pad::DebugDraw(
			m, 
			r, 
			c.Perspective(45.f, (float)winSettings.size.x / (float)winSettings.size.y, 0.1f, 1000.f) * 
			c.LookAt(pad::math::Vec3f(0.f, 0.f, 10.f), pad::math::Vec3f(0.f, 0.f, 0.f), pad::math::Vec3f(0.f, 1.f, 0.f)),
			pad::math::Vec4f(1.f, 0.f, 0.f, 1.f)
		);

		pad::SwapBuffers();
	}

	return EXIT_SUCCESS;
}