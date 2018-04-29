#pragma once

#include <chrono>
#include <map>
#include <vector>
#include <Core/EngineClock.h>
#include <Core/IDPool.h>

namespace pad	{
namespace core	{

class Timer	final																					/*! Timer class that can be used as stop watch */
{
#pragma region Constructor / Destructor
	
public:
	Timer(const bool _affectedByPause = true);														/*!< Default constructor */
	~Timer();																						/*!< Default destructor */	
																				
	Timer(const Timer&) = delete;
	Timer(Timer&&)		= delete;
#pragma endregion

#pragma region Variables

private:
	Timepoint									m_startTime;											/*!< Timepoint when the timer was started */
	double										m_duration;											/*!< Total duration of the timer since it was started */
	double										m_pauseDuration;										/*!< Total time the game have been paused since the timer started */
	unsigned short								m_id;													/*!< Id of the timer */
	bool										m_affectedByPause;									/*!< Bool representing if the timer should be affected by pause or not (true by default) */
												
	Timepoint									m_pauseStartTime;										/*!< Timepoint the game was paused */
	static std::map<unsigned short, Timer*>		m_timerCollection;									/*!< A container for all timers, needed to pause all timers affected by pause if the game is paused */
	static IDPool								m_idPool;

#pragma endregion

#pragma region Member Functions

public:
	void Start();																					/*!< Start the timer */
	void Pause();																					/*!< Pause the timer */
	void Unpause();																					/*!< Unpause the timer */
	void Stop();																					/*!< Stop the timer and save the duration */
	void Reset();

	static void PauseAll();																			/*!< Pause all timers */

#pragma endregion

#pragma region Getter / Setter

public:
	const double GetDuration();																		/*!< Return the current duration of the timer, or the total duration if the timer have been stopped */

#pragma endregion

#pragma region Operators

public:
	Timer& operator=(const Timer&)	= delete;
	Timer& operator=(Timer&&)		= delete;

#pragma endregion
};

} // namespace core
} // namespace pad