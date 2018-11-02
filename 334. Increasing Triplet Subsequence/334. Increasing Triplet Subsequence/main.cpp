//
//  main.cpp
//  334. Increasing Triplet Subsequence
//
//  Created by Jie Lu on 2018/6/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// directly derive from LC300 Longest Increasing Subsequence
//bool increasingTriplet(vector<int>& nums) {
//    vector<int> res;
//    for(int i = 0; i < nums.size(); i++) {
//        auto it = lower_bound(res.begin(), res.end(), nums[i]);
//        if(it == res.end()) {
//            res.push_back(nums[i]);
//        }
//        else
//            *it = nums[i];
//    }
//    return (int)res.size() >= 3;
//}
bool increasingTriplet(vector<int>& nums) {
    int min1 = INT_MAX, min2 = INT_MAX; // keep recording the minimum and the second minimum numbers
    for (auto num : nums) {
        if (num <= min1) {
            min1 = num;
        }
        else if (num <= min2) {
            min2 = num;
        }
        else {
            return true;
            // this number is bigger than the minimum and second minimum numbers, thus we get a 3-number-long increasing subsequence
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
