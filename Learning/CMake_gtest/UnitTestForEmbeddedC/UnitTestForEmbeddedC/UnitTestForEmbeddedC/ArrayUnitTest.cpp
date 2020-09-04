#include "stdafx.h"

#include "Fixture.h"
#include "ModuleMock.h"

#include "Array.c"

using namespace EmbeddedC;
using namespace ::testing;

namespace EmbeddedCUnitTest {

class ArrayUnitTest	: public TestFixture
{
public:
	ArrayUnitTest() : TestFixture(new BaseModuleMock)
	{
		Array_InitGlobals();
	}
};

TEST_F(ArrayUnitTest, PutPositiveTest)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		EXPECT_EQ(0, ArrayPut(i, i));
}

TEST_F(ArrayUnitTest, PutNegativeTest)
{
	EXPECT_EQ(-1, ArrayPut(-1, 1));
	EXPECT_EQ(-1, ArrayPut(ARRAY_SIZE, 1));
}

TEST_F(ArrayUnitTest, GetPositiveTest)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		EXPECT_EQ(0, ArrayPut(i, i));
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		int tmp;
		EXPECT_EQ(0, ArrayGet(i, &tmp));
		EXPECT_EQ(i, tmp);
	}
}

TEST_F(ArrayUnitTest, GetNegativeTest)
{
	int tmp;

	for (int i = 0; i < ARRAY_SIZE; i++)
		EXPECT_EQ(-1, ArrayGet(i, &tmp));
	EXPECT_EQ(-1, ArrayGet(-1, &tmp));
	EXPECT_EQ(-1, ArrayGet(ARRAY_SIZE, &tmp));
}

}
