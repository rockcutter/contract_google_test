#include <gtest/gtest.h>
#include "method.hpp"

TEST(METHOD_TEST, SUCCESS_EXPECTS_AND_ENSURES){
    Hoge hoge;
    ASSERT_EQ(21, hoge.threshold_gt_20_expects_ensures(21, 21));
    ASSERT_EQ(100, hoge.threshold_gt_20_expects_ensures(21, 100));
    ASSERT_EQ(200, hoge.threshold_gt_20_expects_ensures(21, 200));
}

TEST(METHOD_TEST, FAIL_EXPECTS){
    Hoge hoge;
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(20, 21);
        },
        ""
    );
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(10, 21);
        },
        ""
    );
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(0, 21);
        },
        ""
    );
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(-1, 21);
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
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(21, 0);
        },
        ""
    );
    ASSERT_DEATH({
            hoge.threshold_gt_20_expects_ensures(21, -1);
        },
        ""
    );
}
