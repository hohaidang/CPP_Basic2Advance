#include "stdafx.h"

#include "Fixture.h"
#include "QueueMock.h"

#define MOCK_CLASS QueueMock
using namespace EmbeddedCUnitTest;
#include "Queue.c"

using namespace EmbeddedC;
using namespace ::testing;

namespace EmbeddedCUnitTest {

class QueueUnitTest	: public TestFixture
{
public:
	QueueUnitTest() : TestFixture(new ::testing::NiceMock<QueueMock>)
	{
		// We must specify not to return after hook and continue queue code execution.
		// Otherwise the test won't execute queue functions code.
		GetMock<QueueMock>()._returnAfterHookCall = false;
		Queue_InitGlobals();
	}
};

TEST_F(QueueUnitTest, ResetTest)
{
	EXPECT_EQ(0, QueuePush(1));
	EXPECT_EQ(1, QueueCount());
	QueueReset();
	EXPECT_EQ(0, QueueCount());
}

TEST_F(QueueUnitTest, CountTest)
{
	for (auto i = 0; i < QUEUE_SIZE; i++)
		EXPECT_EQ(0, QueuePush(i));
	EXPECT_EQ(QUEUE_SIZE, QueueCount());
}

TEST_F(QueueUnitTest, PushFailureTest)
{
	for (auto i = 0; i < QUEUE_SIZE; i++)
		EXPECT_EQ(0, QueuePush(i));
	EXPECT_EQ(-1, QueuePush(QUEUE_SIZE));
}

TEST_F(QueueUnitTest, PopFailureTest)
{
	int tmp;
	EXPECT_EQ(-1, QueuePop(&tmp));
}

TEST_F(QueueUnitTest, PushAndPopTest)
{
	int tmp;

	for (auto i = 0; i < QUEUE_SIZE; i++)
		EXPECT_EQ(0, QueuePush(i));
	EXPECT_EQ(QUEUE_SIZE, QueueCount());

	for (auto i = 0; i < QUEUE_SIZE; i++)
	{
		EXPECT_EQ(0, QueuePop(&tmp));
		EXPECT_EQ(i, tmp);
	}
	EXPECT_EQ(0, QueueCount());
}

}
