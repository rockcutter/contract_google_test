#pragma once
#include <cstdlib>

template <class T>
T threshold_gt_20_expects_ensures_template(T expects_thres,T ensures_thres)
    [[expects: expects_thres > 20]]
    [[ensures r: r > 20]]
{
    return ensures_thres;
}
