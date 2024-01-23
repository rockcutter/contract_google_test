#pragma once
#include <cstdlib>

int threshold_gt_20_expects_ensures(int expects_test_val,int ensures_test_val)
    [[expects: expects_test_val > 20]]
    [[ensures r: r > 20]]
{
    return ensures_test_val;
}
