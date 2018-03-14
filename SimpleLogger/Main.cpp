#include <iostream>
#include <SimpleLogger.h>

#undef main

void MethodForTestingPurpose()
{
	LOG_INFO("Prout", 1);
}

int main()
{
	MethodForTestingPurpose();

	return EXIT_SUCCESS;
}