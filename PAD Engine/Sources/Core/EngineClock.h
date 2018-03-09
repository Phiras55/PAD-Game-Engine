#pragma once

#include <chrono>

namespace pad	{
namespace core	{

#pragma region Typedef

using Timepoint			= std::chrono::high_resolution_clock::time_point;							/*!< Short name for std::chrono::high_resolution_clock::time_point */
using DurationSeconds	= std::chrono::duration<double>;											/*!< Short name for std::chrono::duration<double> */
using HighResClock		= std::chrono::high_resolution_clock;										/*!< Short name for std::chrono::high_resolution_clock */

#pragma endregion

class EngineClock																					/*! Engine clock used for delta time (frame duration) */
{
#pragma region Constructor / Destructor

public:
	EngineClock()	= default;																		/*!< Default constructor */
	~EngineClock()	= default;																		/*!< Default destructor */

#pragma endregion

#pragma region Variables

private:
	static Timepoint	startTime;																	/*!< Time at the start of the frame */
	static double		deltaTime;																	/*!< Time enlapsed since last frame */
	static float		timeScale;																	/*!< Time scale value, used to slow or speed up the simulation */

#pragma endregion

#pragma region Member Functions

public:
	static void Init();																				/*!< Start the engine clock */
	static void Update();																			/*!< Update the delta time */

#pragma endregion

#pragma region Getter / Setter

public:
	inline static double	DeltaTime()								{ return deltaTime; }			/*!< Get the delta time */
	inline static float&	GetTimeScale()							{ return timeScale; }			/*!< Get the time scale */

	inline static void		SetTimeScale(const float _timeScale)	{ timeScale = _timeScale; }		/*!< Set the time scale */
#pragma endregion
};

} // namespace core
} // namespace pad