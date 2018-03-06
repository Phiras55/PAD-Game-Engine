#include <System/SDLWindow.h>
#include <Graphics/Renderer.h>

namespace pad
{
namespace core
{

class Engine final
{
public:
	Engine();
	~Engine() = default;

	Engine(const Engine&)  = delete;
	Engine(const Engine&&) = delete;

private:
	gfx::Renderer m_renderer;

public:
	void InitSimulation();
	void StartSimulation(); // Run()
	void PollEvents();
	void Update(const float _deltaTime);
	void FixedUpdate(const float _deltaTime);
	void Render();

public:
	void operator=(const Engine&) = delete;
	void operator=(const Engine&&) = delete;
};

} // namespace core
} // namespace pad