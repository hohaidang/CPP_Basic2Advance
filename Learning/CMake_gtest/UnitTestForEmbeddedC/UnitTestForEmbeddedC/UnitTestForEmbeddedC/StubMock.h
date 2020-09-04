#pragma once

#include "ModuleMock.h"

namespace EmbeddedCUnitTest {

class StubMock : public ModuleMock
{
public:
	StubMock()
	{
	}

	MOCK_METHOD0(Foo, void());
};

}
