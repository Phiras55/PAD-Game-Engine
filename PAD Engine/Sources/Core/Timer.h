#pragma once

#include <chrono>
#include <unordered_map>
#include <Core/EngineClock.h>

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
	Timepoint											startTime;									/*!< Timepoint when the timer was started */
	double												duration;									/*!< Total duration of the timer since it was started */
	double												pauseDuration;								/*!< Total time the game have been paused since the timer started */
	unsigned short										id;											/*!< Id of the timer */
	bool												affectedByPause;							/*!< Bool representing if the timer should be affected by pause or not (true by default) */

	Timepoint											pauseStartTime;								/*!< Timepoint the game was paused */
	static std::unordered_map<unsigned short, Timer*>	timerCollection;							/*!< A container for all timers, needed to pause all timers affected by pause if the game is paused */
	static std::vector<unsigned short>					idPool;										/*!< A container for Ids that are free to be re-used */
	static unsigned short								newId;										/*!< The new Id to be used if none are free in the pool */

#pragma endregion

#pragma region Member Functions

public:
	void Start();																					/*!< Start the timer */
	void Pause();																					/*!< Pause the timer */
	void Unpause();																					/*!< Unpause the timer */
	void Stop();																					/*!< Stop the timer and save the duration */

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