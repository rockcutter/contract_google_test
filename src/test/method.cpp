#include <gtest/gtest.h>
#include "method.hpp"

TEST(METHOD_TEST, SUCCESS_EXPECTS_AND_ENSURES){
    Hoge hoge;
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(21, 21);
        },
        ""
    );
}

TEST(METHOD_TEST, FAIL_EXPECTS){
    Hoge hoge;
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(20, 21);
        },
        ""
    );
}

TEST(METHOD_TEST, FAIL_ENSURES){
    Hoge hoge;
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(21, 20);
        },
        ""
    );
}