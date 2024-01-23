#include <cstdlib>
#include "func.hpp"
#include <gtest/gtest.h>

TEST(FUNC_TEST, SUCCESS_EXPECTS_AND_ENSURES){
    ASSERT_EQ(21, threshold_gt_20_expects_ensures(21, 21));
    ASSERT_EQ(100, threshold_gt_20_expects_ensures(21, 100));
    ASSERT_EQ(200, threshold_gt_20_expects_ensures(21, 200));
}

TEST(FUNC_TEST, FAIL_EXPECTS){
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(20, 21);
        },
        ""
    );
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(10, 21);
        },
        ""
    );
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(0, 21);
        },
        ""
    );
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(-1, 21);
        },
        ""
    );
}

TEST(FUNC_TEST, FAIL_ENSURES){
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(21, 20);
        },
        ""
    );
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(21, 0);
        },
        ""
    );
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(21, -1);
        },
        ""
    );
}