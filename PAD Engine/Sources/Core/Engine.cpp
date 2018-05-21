#include <EnginePCH.h>
#include <Core/Engine.h>
#include <Core/Timer.h>
#include <Graphics/GL/GLRenderer.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>
#include <Graphics/GL/Shader/GLFragmentShader.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <System/ECS/MeshRenderer.h>
#include <System/ECS/PerspectiveCamera.h>
#include <System/Physics/BulletContext.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>
#include <Graphics/GL/Shader/GLFragmentShader.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <System/ECS/MeshRenderer.h>
#include <System/ECS/PerspectiveCamera.h>
#include <Graphics/Model/Skeleton.h>

namespace pad	{
namespace core	{

sys::phx::IPhysicContext* Engine::m_physicContext = new sys::phx::BulletContext();

Engine::Engine() :
	m_scene(new sys::ecs::Scene()),
	m_resourceManager(new sys::res::MasterManager())
{

}

Engine::~Engine()
{
	if (m_scene)
		delete m_scene;
	if (m_resourceManager)
		delete m_resourceManager;
}

void Engine::InitSimulation(const gfx::rhi::ContextSettings& _c, const gfx::win::WindowSettings& _w)
{
	LOG_INIT();
	core::EngineClock::Init();

	m_highLevelRenderer.Initialize(_c, _w, m_resourceManager);

	// Test
	sys::ecs::PADObject::SetComponentHandler(&m_componentHandler);
}

void Engine::StartSimulation()
{
	m_scene->Init();
	m_physicContext->Init();
	m_scene->Start();
	m_fixedUpdateTimer.Start();

	while (m_highLevelRenderer.IsWindowOpen())
	{
		Simulate();
	}
}

void Engine::Simulate()
{
	core::EngineClock::Update();
	PollEvents();
	FlushLogs();

	Update();

	if (m_fixedUpdateTimer.GetDuration() >= (1.f / 60.f))
	{
		m_fixedUpdateTimer.Reset();
		FixedUpdate();
	}

	LateUpdate();

	Render();
}

void Engine::PollEvents()
{
	m_highLevelRenderer.PollEvents();
}

void Engine::Update()
{
	m_scene->Update();
}

void Engine::FixedUpdate()
{
	m_physicContext->Update();
	m_scene->FixedUpdate();
}

void Engine::LateUpdate()
{

}

void Engine::Render()
{
	m_highLevelRenderer.Render(*m_resourceManager, *m_scene, m_componentHandler);
}

void Engine::ResizeContext(const uint32 _w, const uint32 _h)
{
	m_highLevelRenderer.ResizeContext(_w, _h);
}

void Engine::FlushLogs()
{
	LOG_FLUSH();
}

void const Engine::GetAnimMatrix(sys::ecs::AnimRenderer& _animRenderer, math::Mat4* _matrixArray)
{
	gfx::mod::Anim*		anim		= m_resourceManager->GetAnimManager().GetResource(_animRenderer.GetAnimName());
	gfx::mod::Skeleton* skeleton	= m_resourceManager->GetSkeletonManager().GetResource(_animRenderer.GetSkeletonName());

	if (!anim)
	{
		for (int i = 0; i < skeleton->GetBoneCount(); ++i)
			_matrixArray[skeleton->GetBones()[i].m_id] = skeleton->GetBones()[i].m_inverseBindPose;

		return;
	}

	if (_animRenderer.GetFrameDuration() == -1)		
		_animRenderer.SetFrameDuration(anim->m_duration / (float)anim->m_frameCount);

	if (_animRenderer.GetTimer().GetDuration() > _animRenderer.GetFrameDuration())
	{
		int key = _animRenderer.GetCurrentFrame() + 1;
		if (key >= anim->m_frameCount)
			key = 0;
		_animRenderer.SetCurrentFrame(key);
		_animRenderer.GetTimer().Reset();
	}

	for (int i = 0; i < anim->m_boneCount; ++i)
	{
		int			boneId		= anim->m_keyFrames[_animRenderer.GetCurrentFrame()].m_bones[i].m_boneId;

		math::Mat4	animMatrix	= anim->m_keyFrames[_animRenderer.GetCurrentFrame()].m_bones[i].m_transform;
		math::Mat4	bindMatrix	= skeleton->GetBoneById(boneId)->m_inverseBindPose;
		_matrixArray[boneId]	= animMatrix * bindMatrix;
//		_matrixArray[boneId]	= bindMatrix * animMatrix;

//		_matrixArray[boneId] = skeleton->GetBoneById(boneId)->m_inverseBindPose * anim->m_keyFrames[_animRenderer.GetCurrentFrame()].m_bones[i].m_transform;
	}
}

} // namespace core
} // namespace pad