//
//  main.cpp
//  300. Longest Increasing Subsequence
//
//  Created by Jie Lu on 2018/6/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// O(n^2) solution. Very easy-understanding.
//int lengthOfLIS(vector<int>& nums) {
//    int size = (int)nums.size();
//    if (size == 0) {
//        return 0;
//    }
//    vector<int> dp(size, 1);
//    int res = 1;
//    for (int i = 1; i < size; ++i) {
//        for (int j = 0; j < i; ++j) {
//            if (nums[j] < nums[i]) {
//                dp[i] = max(dp[i], dp[j]+1);
//            }
//        }
//        res = max (res, dp[i]);
//    }
//    return res;
//}

// O(nlogn) solution.
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        auto it = lower_bound(res.begin(), res.end(), nums[i]);
        if(it == res.end()) {
            res.push_back(nums[i]);
        }
        else
            *it = nums[i];
    }
    return (int)res.size();
}

int main(int argc, const char * argv[]) {
    vector<int> nums{10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}
