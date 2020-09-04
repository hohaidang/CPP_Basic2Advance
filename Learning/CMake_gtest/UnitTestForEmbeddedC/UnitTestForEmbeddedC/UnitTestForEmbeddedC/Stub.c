
#include "Stub.h"
#include "MockHooks.h"


#if defined(__cplusplus)
namespace EmbeddedC {
#endif

void Foo()
{
	MOCK_HOOK_P0(Foo);
}

#if defined(__cplusplus)
}
#endif
