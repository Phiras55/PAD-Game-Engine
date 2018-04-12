#pragma once

#include <System/ECS/AScriptComponent.h>

class ScriptTest : public pad::sys::ecs::AScriptComponent
{
public:
	ScriptTest()	= default;
	~ScriptTest()	= default;
public:
	void Init()			override;
	void Start()		override;
	void Update()		override;
	void FixedUpdate()	override;
	void LateUpdate()	override;

private:
	float pos_y;
};