#include "stdafx.h"

#include "Fixture.h"

#include "CallingServices.c"

using namespace EmbeddedC;
using namespace ::testing;

namespace EmbeddedCUnitTest {

class CallingServicesUnitTest : public TestFixture
{
public:
	CallingServicesUnitTest() : TestFixture(new ModuleMock)
	{
		CallingServices_InitGlobals();
	}
};

TEST_F(CallingServicesUnitTest, ShortcutTest)
{
	EXPECT_CALL(*_oscillator, GetTime()).Times(3).WillOnce(Return(10)).WillOnce(Return(100)).WillOnce(Return(111));
	EXPECT_CALL(*_gpio, ReadGpio(0, _)).Times(1).WillOnce(DoAll(SetArgPointee<1>(1), Return(0)));
	EXPECT_CALL(*_gpio, WriteGpio(1, 1)).Times(1);

	int timeout = 100;
	ShortCircuit(timeout);
}

}
