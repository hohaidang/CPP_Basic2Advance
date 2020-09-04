#pragma once

#include "ModuleMock.h"

namespace EmbeddedC
{
	void Queue_InitGlobals();
}

namespace EmbeddedCUnitTest {

class QueueMock : public ModuleMock
{
public:
	QueueMock()
	{
		EmbeddedC::Queue_InitGlobals();
	}

	MOCK_METHOD0(QueueReset, void());
	MOCK_METHOD0(QueueCount, int());
	MOCK_METHOD1(QueuePush, int(int));
	MOCK_METHOD1(QueuePop, int(int*));
};

}
