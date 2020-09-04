
#include "Array.h"


#if defined(__cplusplus)
namespace EmbeddedC {
#endif

#define ARRAY_SIZE 15

static int array[ARRAY_SIZE];
static int initialized[ARRAY_SIZE];

void Array_InitGlobals()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		initialized[i] = 0;
}

int ArrayPut(int idx, int i)
{
	if (idx < 0 || idx >= ARRAY_SIZE)
		return -1;

	array[idx] = i;
	initialized[i] = 1;
	return 0;
}

int ArrayGet(int idx, int* i)
{
	if (idx < 0 || idx >= ARRAY_SIZE)
		return -1;

	if (initialized[idx] == 0)
		return -1;

	*i = array[idx];
	return 0;
}

#if defined(__cplusplus)
}
#endif
