#pragma once

#include <chrono>

#pragma region Typedef

using Timepoint = std::chrono::high_resolution_clock::time_point;

#pragma endregion

namespace pad	{
namespace core	{

static class EngineClock
{
#pragma region Constructor / Destructor

public:
	EngineClock();
	~EngineClock() = default;

#pragma endregion

#pragma region Variables

private:
	static double deltaTime;
	static Timepoint startTime;
	static Timepoint endTime;

#pragma endregion

#pragma region Member Functions

public:
	static void Init();
	static void Update();

#pragma endregion

#pragma region Getter / Setter

public:
	static float GetDeltaTime() { return deltaTime; }

#pragma endregion
};

} // namespace core
} // namespace pad