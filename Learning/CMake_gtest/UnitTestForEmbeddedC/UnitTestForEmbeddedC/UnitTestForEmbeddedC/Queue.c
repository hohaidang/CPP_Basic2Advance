
#include "Queue.h"
#include "MockHooks.h"

#if defined(__cplusplus)
namespace EmbeddedC {
#endif

#define QUEUE_SIZE 15

static int queue[QUEUE_SIZE];
static int head;
static int tail;
static int count;

void Queue_InitGlobals()
{
	head = tail = count = 0;
}

void QueueReset()
{
	MOCK_HOOK_P0(QueueReset);

	Queue_InitGlobals();
}

int QueueCount()
{
	MOCK_HOOK_P0(QueueCount);

	return count;
}

int QueuePush(int i)
{
	MOCK_HOOK_P1(QueuePush, i);

	if (count == QUEUE_SIZE)
		return -1;
	queue[tail] = i;
	tail = (tail + 1) % QUEUE_SIZE;
	count++;
	return 0;
}

int QueuePop(int *i)
{
	MOCK_HOOK_P1(QueuePop, i);

	if (count == 0)
		return -1;
	*i = queue[head];
	head = (head + 1) % QUEUE_SIZE;
	count--;
	return 0;
}

#if defined(__cplusplus)
}
#endif
