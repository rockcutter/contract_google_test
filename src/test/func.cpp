#include <cstdlib>
#include "func.hpp"
#include <gtest/gtest.h>

TEST(FUNC_TEST, SUCCESS_EXPECTS_AND_ENSURES){
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(21, 21);
        },
        ""
    );
}

TEST(FUNC_TEST, FAIL_EXPECTS){
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures(20, 21);
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
}