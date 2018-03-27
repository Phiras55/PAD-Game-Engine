#include <Core/Timer.h>

namespace pad	{
namespace core	{

#pragma region Statics

std::map<unsigned short, Timer*>	Timer::timerCollection;
IDPool								Timer::idPool;

#pragma endregion

#pragma region Constructor / Destructor

Timer::Timer(const bool _affectedByPause) :
	duration(-1),
	pauseDuration(0)
{
	id = idPool.GenerateID();

	timerCollection[id] = this;
}

Timer::~Timer()
{
	timerCollection[id] = nullptr;
	idPool.FreeID(id);
}

#pragma endregion

#pragma region Member Functions

void Timer::Start()
{
	startTime = HighResClock::now();
}

void Timer::Pause()
{
	pauseStartTime = HighResClock::now();
}

void Timer::Unpause()
{
	Timepoint pauseEndTime = HighResClock::now();

	pauseDuration += (	DurationSeconds(pauseEndTime - pauseStartTime).count() 
						* core::EngineClock::GetTimeScale());
}

void Timer::Stop()
{
	Timepoint endTime = HighResClock::now();

	duration =	(	(DurationSeconds(endTime - startTime).count() - pauseDuration)
					* core::EngineClock::GetTimeScale());
}

void Timer::PauseAll()
{
	for (std::pair<int, Timer*> timer : timerCollection)
	{
		if (timer.second->affectedByPause)
			timer.second->Pause();
	}
}

#pragma endregion

#pragma region Getter / Setter

const double Timer::GetDuration()
{
	Timepoint endTime = HighResClock::now();

	if (duration < 0)
		return	(DurationSeconds(endTime - startTime).count() - pauseDuration)
				* core::EngineClock::GetTimeScale();

	else
		return duration;
}

#pragma endregion

} // namespace core
} // namespace pad