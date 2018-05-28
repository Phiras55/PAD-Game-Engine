#include <PCH.h>
#include <Graphics/Inputs/Inputs.h>

namespace pad	{
namespace inp	{

std::map<alias::KeyCode, InputData> Inputs::m_keyData;
alias::State						Inputs::m_pressedState;
alias::State						Inputs::m_releasedState;
math::Vec2u							Inputs::m_mousePosition;

bool Inputs::GetIsKeyPressed (alias::KeyCode _key)
{
	if (m_keyData.find(_key) != m_keyData.end())
		return m_keyData[_key].state == m_pressedState;

	return false;
}

bool Inputs::GetIsKeyReleased(alias::KeyCode _key)
{
	if (m_keyData.find(_key) != m_keyData.end())
		return m_keyData[_key].state == m_releasedState;

	return false;
}

bool Inputs::GetIsKeyRepeated(alias::KeyCode _key)
{
	if (m_keyData.find(_key) != m_keyData.end())
		return (m_keyData[_key].state == m_pressedState && m_keyData[_key].oldState == m_pressedState);

	return false;
}

void Inputs::BindInput(const alias::KeyCode& _key, const alias::Function& _func, bool _isToggleKey, float32 _cooldown)
{
	m_keyData[_key] = inp::InputData(m_releasedState, m_releasedState, _isToggleKey, _func, _cooldown);
}

void Inputs::UpdateInputs(const float32 _deltatime)
{
	for (auto it = m_keyData.begin(), end = m_keyData.end(); it != end; ++it)
	{
		if (it->second.isToggle)
		{
			if (it->second.state == m_releasedState && it->second.oldState == m_pressedState)
			{
				if (it->second.func)
				{
					it->second.func();
					it->second.oldState = it->second.state;
				}
			}
		}
		else
		{
			it->second.elapsed += _deltatime;
			if (it->second.elapsed >= it->second.cooldown)
			{
				if (it->second.state == m_pressedState)
				{
					it->second.elapsed = 0.f;
					if (it->second.func)
					{
						it->second.func();
					}
				}
			}
		}
	}
}

void Inputs::SetKeyState(const alias::KeyCode& _key, const alias::State& _state)
{
	m_keyData[_key].oldState	= m_keyData[_key].state;
	m_keyData[_key].state		= _state;
}

void Inputs::SetPressedState(const alias::State& _state)
{
	m_pressedState = _state;
}

void Inputs::SetReleasedState(const alias::State& _state)
{
	m_releasedState = _state;
}

const alias::State& Inputs::PressedState()
{
	return m_pressedState;
}

const alias::State& Inputs::ReleasedState()
{
	return m_releasedState;
}

}
}