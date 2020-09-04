
// This file is not a part of testing, but only an example of service that need to be mocked.
// For the mock implementation refer to FakeServices.cpp and ServicesMocks.h files.

#include "Gpio.h"

#if defined(__cplusplus)
namespace EmbeddedC {
#endif

int ReadGpio(int line, int *value)
{
	// Code that reads from GPIO line
	return 0;
}

int WriteGpio(int line, int value)
{
	// Code that writes to GPIO line
	return 0;
}

#if defined(__cplusplus)
}
#endif
