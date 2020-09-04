#ifndef __QUEUE_H__
#define __QUEUE_H__

#if defined(__cplusplus)
namespace EmbeddedC {
#endif

void QueueReset();
int QueueCount();
int QueuePush(int i);
int QueuePop(int *i);

#if defined(__cplusplus)
}
#endif

#endif /*__QUEUE_H__*/
