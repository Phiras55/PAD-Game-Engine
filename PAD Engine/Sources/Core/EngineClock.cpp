#include <EnginePCH.h>
#include <Core/EngineClock.h>

namespace pad	{
namespace core	{

#pragma region Statics

Timepoint	EngineClock::startTime	= HighResClock::now();
double		EngineClock::deltaTime	= 0;
float		EngineClock::timeScale	= 1.f;

#pragma endregion

#pragma region Member Functions

void EngineClock::Init()
{
	startTime = HighResClock::now();
}

void EngineClock::Update()
{
	Timepoint endTime	= HighResClock::now();
	deltaTime			= DurationSeconds(endTime - startTime).count() * timeScale;
	startTime			= endTime;
}

#pragma endregion

} // namespace core
} // namespace pad