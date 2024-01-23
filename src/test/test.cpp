// googleテストどう書くんだっけっていうテスト

#include <gtest/gtest.h>

TEST(GOOGLETEST_TEST, ASSERT_TRUE){
    EXPECT_TRUE(true);
}

TEST(GOOGLETEST_TEST, DEATH_TEST_1){
    ASSERT_DEATH({
        abort();
    }, "");
}

