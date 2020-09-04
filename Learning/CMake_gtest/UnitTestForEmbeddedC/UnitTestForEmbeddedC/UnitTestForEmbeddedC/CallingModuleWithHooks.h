#ifndef __WORKER_H__
#define __WORKER_H__

#if defined(__cplusplus)
namespace EmbeddedC {
#endif

int OnDataReceived(int data);
int OnReadCommand(int *data);
void OnResetCommand();

#if defined(__cplusplus)
}
#endif

#endif /*__WORKER_H__*/
