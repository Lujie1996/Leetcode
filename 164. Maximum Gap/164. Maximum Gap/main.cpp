//
//  main.cpp
//  164. Maximum Gap
//
//  Created by Jie Lu on 2018/8/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//int maximumGap(vector<int>& nums) {
//    sort(nums.begin(), nums.end());s
//    int maxGap = 0;
//    for (int i = 1; i < nums.size(); i++) {
//        maxGap = max(maxGap, nums[i] - nums[i-1]);
//    }
//    return maxGap;
//}

/*
 Pigeonhole Pricipal + Bucket Sort
 Suppose there are N elements and they range from A to B.
 Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]
    -> Use the possible minimum gap as bucket size in order to keep the number of buckets as small as possible
 Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket
 */
int maximumGap(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int maxNum = nums[0], minNum = nums[0];
    for (auto num : nums) {
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
    }
    double len = (double)(maxNum - minNum) / (nums.size() - 1);
    if(len == 0)
        return 0;
    int cnt = floor((maxNum - minNum) / len + 1);
    vector<int> minb(cnt, INT_MAX), maxb(cnt, INT_MIN);
    for(int i = 0; i < nums.size(); i++)
    {
        int id = floor((nums[i] - minNum) / len);
        minb[id] = min(minb[id], nums[i]);
        maxb[id] = max(maxb[id], nums[i]);
    }
    int res = 0, premax = maxb[0];
    for(int i = 1; i < cnt; i++)
    {
        if(minb[i] != INT_MAX)
        {
            res = max(res, minb[i] - premax);
            premax = maxb[i];
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{3,6,9,1};
    cout<<maximumGap(nums)<<endl;
    return 0;
}
