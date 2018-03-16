#include <iostream>

#define LOGGER
#include <Logger/SimpleLogger.h>

#undef main

#define LOGGER

void MethodForTestingPurpose()
{
	LOG_INIT();

	LOG_INFO("Too much arguments and no delimiter.\n", 1, 2, 3, 4, 5);
	LOG_TRACE("Too much argument with delimiters. %%\n", 1, 2, 3, 4, 5);
	LOG_WARNING("Not enough arguments. %% + %%\n", 1);
	LOG_ERROR("No arguments with delimiter. %%\n", 0);
	LOG_FATAL("No arguments and no delimiter.\n", 0);
	LOG_INFO_S("Just perfect one. %%\n");
	LOG_CUSTOM(ChanType::INFO | ChanType::ERROR, "I am in INFO and ERROR\n", 0);

	LOG_FLUSH();
}

int main()
{
	MethodForTestingPurpose();

	return EXIT_SUCCESS;
}