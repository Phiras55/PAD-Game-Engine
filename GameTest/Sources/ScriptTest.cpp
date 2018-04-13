#include "ScriptTest.h"
#include <Core/EngineClock.h>

void ScriptTest::Init()
{	
	AScriptComponent::Init();
	pos_y = -2;
}

void ScriptTest::Start()
{

}

void ScriptTest::Update()
{
	pos_y += pad::core::EngineClock::DeltaTime() * 0.5;
	m_owner->GetTransform().SetPosition(pad::math::Vec3f(0, pos_y, 0));
}

void ScriptTest::FixedUpdate()
{
}

void ScriptTest::LateUpdate()
{
}