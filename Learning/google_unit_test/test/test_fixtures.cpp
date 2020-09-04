#include "gtest/gtest.h"
using namespace std;

class my_class {
private:
	int m_value = 0;
public:
	my_class(int value) : m_value(value) {};
	void increase(int val) {
		m_value += val;
	}
	int get_val() { return m_value; }
};

/* Test Fixtures */
struct my_class_test : public testing::Test { 
	my_class *mc;
	void SetUp() { mc = new my_class(0); }
	void TearDown() { delete mc; }
};

TEST_F(my_class_test, increase_by_3) {
	mc->increase(3);
	int actual = mc->get_val();
	int expected = 3;
	EXPECT_EQ(actual, expected);
}

TEST_F(my_class_test, increase_by_10) {
	mc->increase(10);
	int actual = mc->get_val();
	int expected = 10;
	EXPECT_EQ(actual, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}