
#include "CallingServices.h"
#include "Gpio.h"
#include "Oscillator.h"


#if defined(__cplusplus)
namespace EmbeddedC {
#endif

static void CallingServices_InitGlobals()
{
}

void ShortCircuit(int timeout)
{
	int startTime = GetTime();
	while(GetTime() - startTime < timeout)
	{
		int signal;
		ReadGpio(0, &signal);
		WriteGpio(1, signal);
	}
}

#if defined(__cplusplus)
}
#endif
