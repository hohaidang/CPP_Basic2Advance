#include "stdafx.h"

#include "Fixture.h"
#include "QueueMock.h"
#include "StubMock.h"

#include "CallingModuleWithHooks.c"

using namespace EmbeddedC;
using namespace ::testing;

namespace EmbeddedCUnitTest {

namespace {

class Mock
	: public ::testing::StrictMock<QueueMock>
	, public ::testing::NiceMock<StubMock>
{

};

}

class CallingModuleWithHooksUnitTest : public TestFixture
{
public:
	CallingModuleWithHooksUnitTest() : TestFixture(new Mock)
	{
		CallingModuleWithHooks_InitGlobals();

		// Here is example of redefining services in test fixture class
		_gpio.reset(new ::testing::StrictMock<GpioService>());
	}
};

TEST_F(CallingModuleWithHooksUnitTest, OnDataReceivedPositiveTest)
{
	EXPECT_CALL(GetMock<QueueMock>(), QueuePush(1)).Times(1).WillRepeatedly(Return(0));

	EXPECT_EQ(0, OnDataReceived(1));
}

TEST_F(CallingModuleWithHooksUnitTest, OnDataReceivedNegativeTest)
{
	EXPECT_CALL(GetMock<QueueMock>(), QueuePush(1)).Times(1).WillRepeatedly(Return(-1));
	EXPECT_CALL(*_gpio, WriteGpio(10, 1)).Times(1);

	EXPECT_EQ(-1, OnDataReceived(1));
}

TEST_F(CallingModuleWithHooksUnitTest, OnReadCommandPositiveTest)
{
	EXPECT_CALL(GetMock<QueueMock>(), QueuePop(_)).Times(1).WillRepeatedly(DoAll(SetArgPointee<0>(1000), Return(0)));

	int tmp;
	EXPECT_EQ(0, OnReadCommand(&tmp));
	EXPECT_EQ(1000, tmp);
}

TEST_F(CallingModuleWithHooksUnitTest, OnReadCommandNegativeTest)
{
	EXPECT_CALL(GetMock<QueueMock>(), QueuePop(_)).Times(1).WillRepeatedly(Return(-1));
	EXPECT_CALL(*_gpio, WriteGpio(11, 1)).Times(1);

	int tmp;
	EXPECT_EQ(-1, OnReadCommand(&tmp));
}

TEST_F(CallingModuleWithHooksUnitTest, OnResetCommandTest)
{
	EXPECT_CALL(GetMock<QueueMock>(), QueueReset());
	EXPECT_CALL(*_gpio, WriteGpio(10, 0)).Times(1);
	EXPECT_CALL(*_gpio, WriteGpio(11, 0)).Times(1);

	OnResetCommand();
}

}
