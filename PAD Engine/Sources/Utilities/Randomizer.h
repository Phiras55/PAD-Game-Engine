#pragma once 
#include <cstdlib>
#include <random> 
#include <ctime>

/**
Initialize random methods.
return void.
**/
void InitRandomizer()
{										
	srand(static_cast<unsigned>(time(0)));
}

/**
The basic templated Randomize method.
param T Min [Inclusive].
param T Max [Exclusive].
return T value. */
template<typename T>
inline T RandomizeI(T min, T max)
{
	T r = max +1;
	do
		r = min + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (max+1 - min)));
	while (r > max);
	return r;
}

/**
The basic templated Randomize method for integer numbers.
param T Min [Inclusive].
param T Max [Inclusive].
return T value. */
template<typename T>
inline T RandomizeF(T min, T max)
{
	return min + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (max - min)));
}

/**
The basic templated Randomize method for floating numbers.
param T Min [Inclusive].
param T Max [Inclusive].
return T value. */
template<typename T>
inline T RandomizeP(T min, T max)
{
	T r = ((rand() * (max - min)) / RAND_MAX) + min;
	return r;
}

/**
Bool randomizing method (true/false).
return bool value. **/
bool RandomizeBool()
{
	return (RandomizeI(0, 1) == 0) ? true : false;
}

/**
Int randomizing method (0/1).
return bool value. **/
int RandomizeInt()
{
	return RandomizeI(0, 1);
}

/**
Unsigned int randomizing method (0u / 1u).
return unsigned int value. **/
unsigned int RandomizeUInt()
{
	return RandomizeI(0u, 1u);;
}

/**
Float randomizing method (0.0f - 1.0f).
return float value. **/
float RandomizeFloat()
{
	return RandomizeF(0.f, 1.f);
}

/**
Double randomizing method (0.0 - 1.0).
return double value. **/
double RandomizeDouble()
{
	return RandomizeF(0.0, 1.0);
}
