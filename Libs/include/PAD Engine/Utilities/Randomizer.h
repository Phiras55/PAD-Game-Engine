#pragma once 
#include <cstdlib>

/**
Initialize random methods.
return void.
**/
void InitRandomizer();

/**
Bool randomizing method (true/false).
return bool value. **/
bool			Randomize_Bool();

/**
Int randomizing method (0/1).
return bool value. **/
int				Randomize_Int();

/**
Unsigned int randomizing method (0u / 1u).
return unsigned int value. **/
unsigned int	Randomize_UInt();

/**
Float randomizing method (0.0f - 1.0f).
return float value. **/
float			Randomize_Float();

/**
Double randomizing method (0.0 - 1.0).
return double value. **/
double			Randomize_Double();

/**
The basic templated Randomize method.
param T Min [Inclusive].
param T Max [Exclusive].
return T value. */
template<typename T>
T Randomize(T min, T max)
{
	T r = min + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (max+1 - min)));
	return r;
}