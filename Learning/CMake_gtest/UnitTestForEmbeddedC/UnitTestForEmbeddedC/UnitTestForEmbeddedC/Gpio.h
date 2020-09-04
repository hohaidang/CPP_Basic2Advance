#ifndef __GPIO_H__
#define __GPIO_H__

#if defined(__cplusplus)
namespace EmbeddedC {
#endif

int ReadGpio(int line, int *value);
int WriteGpio(int line, int value);

#if defined(__cplusplus)
}
#endif

#endif /*__GPIO_H__*/
