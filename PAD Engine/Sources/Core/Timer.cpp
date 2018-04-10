#include <Core/Timer.h>

namespace pad	{
namespace core	{

#pragma region Statics

std::map<unsigned short, Timer*>	Timer::m_timerCollection;
IDPool								Timer::m_idPool;

#pragma endregion

#pragma region Constructor / Destructor

Timer::Timer(const bool _affectedByPause) :
	m_duration(-1),
	m_pauseDuration(0)
{
	m_id = m_idPool.GenerateID();

	m_timerCollection[m_id] = this;
}

Timer::~Timer()
{
	m_timerCollection[m_id] = nullptr;
	m_idPool.FreeID(m_id);
}

#pragma endregion

#pragma region Member Functions

void Timer::Start()
{
	m_startTime = HighResClock::now();
}

void Timer::Pause()
{
	m_pauseStartTime = HighResClock::now();
}

void Timer::Unpause()
{
	Timepoint pauseEndTime = HighResClock::now();

	m_pauseDuration += (	DurationSeconds(pauseEndTime - m_pauseStartTime).count() 
						*	core::EngineClock::GetTimeScale());
}

void Timer::Stop()
{
	Timepoint endTime = HighResClock::now();

	m_duration =	(	(DurationSeconds(endTime - m_startTime).count() - m_pauseDuration)
					*	core::EngineClock::GetTimeScale());
}

void Timer::ResetDuration()
{
	m_startTime = HighResClock::now();
}

void Timer::PauseAll()
{
	for (std::pair<int, Timer*> timer : m_timerCollection)
	{
		if (timer.second->m_affectedByPause)
			timer.second->Pause();
	}
}

#pragma endregion

#pragma region Getter / Setter

const double Timer::GetDuration()
{
	Timepoint endTime = HighResClock::now();

	if (m_duration < 0)
		return	(DurationSeconds(endTime - m_startTime).count() - m_pauseDuration)
				* core::EngineClock::GetTimeScale();

	else
		return m_duration;
}

#pragma endregion

} // namespace core
} // namespace pad