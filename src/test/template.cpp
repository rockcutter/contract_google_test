#include <gtest/gtest.h> 
#include "template.hpp"

TEST(TEMPLATE_TEST, SUCCESS_EXPECTS_AND_ENSURES){
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures_template(21, 21);
        },
        ""
    );
}

TEST(TEMPLATE_TEST, FAIL_EXPECTS){
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures_template(20, 21);
        },
        ""
    );
}

TEST(TEMPLATE_TEST, FAIL_ENSURES){
    ASSERT_DEATH({
            threshold_gt_20_expects_ensures_template(21, 20);
        },
        ""
    );
}