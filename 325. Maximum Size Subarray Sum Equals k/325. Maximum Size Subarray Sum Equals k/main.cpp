//
//  main.cpp
//  325. Maximum Size Subarray Sum Equals k
//
//  Created by Jie Lu on 2018/7/20.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//int maxSubArrayLen(vector<int>& nums, int k) {
//    unordered_map<int, int> sumIndex;
//    int sum = 0, res = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        sum += nums[i];
//        if (sum == k) {
//            res = max(res, i + 1);
//        }
//        else {
//            auto it = sumIndex.find(sum - k);
//            if (it != sumIndex.end()) {
//                res = max(res, i - it->second);
//            }
//        }
//        if (sumIndex.find(sum) == sumIndex.end()) {
//            sumIndex[sum] = i;
//            // This is very important. Doing this guarantees that i does not overwrite a smaller index j that also has sumIndex[j] == sum.
//            // Always keep sumIndex[sum] as small as possible, otherwise the previous (i - it->second) would not get the possible minimum length.
//        }
//    }
//    return res;
//}

// my code in 2018/11/11
int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int,int> sumIndex;
    sumIndex[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size() ;i++) {
        sum += nums[i];
        if (sumIndex.find(sum) == sumIndex.end()) {
            sumIndex[sum] = i;
        }
    }
    
    int res = 0;
    sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        auto it = sumIndex.find(sum - k);
        if (it != sumIndex.end() && i > sumIndex[sum-k]) {
            res = max(res, i - sumIndex[sum-k]);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{-1};
    cout<<maxSubArrayLen(nums, -1)<<endl;
    return 0;
}
