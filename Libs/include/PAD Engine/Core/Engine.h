#include <Core/EngineClock.h>
#include <Graphics/HighLevelRenderer.h>
#include <Graphics/RHI/RenderSettings.h>
#include <Graphics/Model/Mesh.h>
#include <System/Scene/Scene.h>
#include <System/ResourceHandling/MasterManager.h>
#include <System/ResourceHandling/ResourceManager.h>
#include <System/Physics/IPhysicContext.h>
#include <System/ResourceHandling/ComponentsHandler.h>
#include <System/ECS/AnimRenderer.h>
#include <Core/Timer.h>
#include <Core/IDHandler.h>

namespace pad	{
namespace core	{

class Engine final
{
public:
	Engine();
	~Engine();

	Engine(const Engine&)  = delete;
	Engine(const Engine&&) = delete;

private:
	gfx::HighLevelRenderer		m_highLevelRenderer;

	sys::ecs::Scene*			m_scene;
	sys::res::MasterManager*	m_resourceManager;
	sys::res::ComponentsHandler m_componentHandler;

	Timer m_fixedUpdateTimer;

private:
	static sys::phx::IPhysicContext*	m_physicContext;

public:
	void InitSimulation(const gfx::rhi::ContextSettings& _c, const gfx::win::WindowSettings& _w);			/*! Initialize the simulation. Reads the config files and initialize the renderer and the window. */
	void StartSimulation();																					/*! Starts the simulation with the parameters given in InitSimulation method. */
	void Simulate();

private:
	void PollEvents();
	void Update();
	void FixedUpdate();
	void LateUpdate();
	void Render();

	void ResizeContext(const uint32 _w, const uint32 _h);
	void FlushLogs();

public:
	sys::ecs::Scene* const				GetScene() const			{ return m_scene; }
	sys::res::MasterManager* const		GetResourceManager() const	{ return m_resourceManager; }
	const	gfx::HighLevelRenderer&		GetRenderer() const			{ return m_highLevelRenderer; }
			gfx::HighLevelRenderer&		GetRenderer()				{ return m_highLevelRenderer; }

public:
	static sys::phx::IPhysicContext* const GetPhysicContext() { return m_physicContext; }

public:
	void const GetAnimMatrix(sys::ecs::AnimRenderer& _anim, math::Mat4* _matrixArray);

public:
	void operator=(const Engine&)	= delete;
	void operator=(const Engine&&)	= delete;
};

} // namespace core
} // namespace pad