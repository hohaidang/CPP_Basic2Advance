#ifndef __ARRAY_H__
#define __ARRAY_H__

#if defined(__cplusplus)
namespace EmbeddedC {
#endif

int ArrayPut(int idx, int i);
int ArrayGet(int idx, int* i);

#if defined(__cplusplus)
}
#endif

#endif /*__ARRAY_H__*/
