#include <iostream>
#include <Core/EngineDLL.h>

int main()
{
	pad::CreateEngine();
	pad::InitEngine();

	// Will be read from a config file
	pad::sys::WindowSettings winSettings;

	winSettings.title = "This is a SDL Window.";
	winSettings.position.x = 400u;
	winSettings.position.y = 200u;
	winSettings.size.x = 800u;
	winSettings.size.y = 600u;
	winSettings.isFullscreen = false;
	winSettings.windowType = pad::sys::E_WINDOW_TYPE::ENGINE;

	// Will be read from a config file
	pad::gfx::rhi::RenderSettings renderSettings;

	renderSettings.viewportSize.x = winSettings.size.x;
	renderSettings.viewportSize.y = winSettings.size.y;
	renderSettings.clearColor.r = 0.3f;
	renderSettings.clearColor.g = 0.3f;
	renderSettings.clearColor.b = 0.3f;
	renderSettings.clearColor.a = 1.0f;

	pad::InitWindow(winSettings);
	pad::InitRenderer(renderSettings);

	while (true)
	{
		pad::PollEvents();

		pad::ClearBuffer();

		pad::SwapBuffers();
	}

	return EXIT_SUCCESS;
}