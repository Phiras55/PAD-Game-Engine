#pragma once
#include <Graphics/Inputs/InputData.h>

namespace pad	{
namespace inp	{

class Inputs final
{
private:
	static std::map<alias::KeyCode, InputData> m_keyData;
	static alias::State m_pressedState;
	static alias::State m_releasedState;
	static math::Vec2u m_mousePosition;

public:
	static void			UpdateInputs(const float32 _deltatime);
	static void			SetKeyState(const alias::KeyCode& _key, const alias::State& _state);
	static bool			GetIsKeyPressed (alias::KeyCode _key);
	static bool			GetIsKeyReleased(alias::KeyCode _key);
	static bool			GetIsKeyRepeated(alias::KeyCode _key);
	static void			BindInput(const alias::KeyCode& _key, const alias::Function& _func, bool _isToggleKey, float32 _cooldown);

	static void SetPressedState(const alias::State& _state);
	static void SetReleasedState(const alias::State& _state);

	static const alias::State& PressedState();
	static const alias::State& ReleasedState();
};

}
}