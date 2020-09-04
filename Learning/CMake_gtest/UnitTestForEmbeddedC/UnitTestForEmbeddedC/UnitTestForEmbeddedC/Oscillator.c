
// This file is not a part of testing, but only an example of service that need to be mocked.
// For the mock implementation refer to FakeServices.cpp and ServicesMocks.h files.

#include "Oscillator.h"

#if defined(__cplusplus)
namespace EmbeddedC {
#endif

int GetTime()
{
	// Code that reads oscillator register
	return 0;
}

#if defined(__cplusplus)
}
#endif
