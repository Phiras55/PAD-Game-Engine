#pragma once
#include <PCH.h>

namespace pad	{
namespace inp	{

	namespace alias
	{
		using KeyCode	= uint32;
		using State		= uint32;
		using OldState	= uint32;
		using Function	= std::function<void()>;
	}

	struct InputData
	{
		InputData()
		{
			state		= 0u;
			oldState	= 0u;
			isToggle	= false;
			func		= nullptr;
			cooldown	= 0.f;
			elapsed		= 0.f;
		}

		InputData(alias::State _state, alias::OldState _oldState, bool _isToggle, alias::Function _func, float32 _cooldown)
		{
			state		= _state;
			oldState	= _oldState;
			isToggle	= _isToggle;
			func		= _func;
			cooldown	= _cooldown;
			elapsed		= 0.f;
		}

		alias::State			state;
		alias::OldState			oldState;
		bool					isToggle;
		float					cooldown;
		float					elapsed;
		std::function<void()>	func;
	};

}
}