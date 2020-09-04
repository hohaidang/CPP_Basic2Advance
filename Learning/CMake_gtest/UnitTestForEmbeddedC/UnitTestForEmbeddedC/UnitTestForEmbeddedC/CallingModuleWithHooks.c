
#include "CallingModuleWithHooks.h"
#include "Gpio.h"
#include "Queue.h"
#include "Stub.h"


#if defined(__cplusplus)
namespace EmbeddedC {
#endif

static void CallingModuleWithHooks_InitGlobals()
{
}

int OnDataReceived(int data)
{
	if (QueuePush(data) == -1)
	{
		WriteGpio(10, 1);
		return -1;
	}

	Foo();
	return 0;
}

int OnReadCommand(int *data)
{
	if (QueuePop(data) == -1)
	{
		WriteGpio(11, 1);
		return -1;
	}
	
	Foo();
	return 0;
}

void OnResetCommand()
{
	QueueReset();
	WriteGpio(10, 0);
	WriteGpio(11, 0);
}

#if defined(__cplusplus)
}
#endif
