#include <gtest/gtest.h>
#include "../example.h"

TEST(ExampleTests, Demo) {
    EXPECT_TRUE(true);
}

TEST(ExampleTests, Demo1) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(ExampleTests, increasement) {
    int a = 5;
    EXPECT_EQ(increasement(a), 154);

}