//
//  main.cpp
//  31. Next Permutation
//
//  Created by Jie Lu on 2018/4/4.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//void nextPermutation(vector<int>& nums) {
//    int i, j;
//    i = j = (int)nums.size() - 1;
//    // iterate from right to left, see where breaks the ascending order.
//    while (i > 0 && nums[i-1] >= nums[i]) {
//        i--;
//    }
//    if (i == 0) {
//        // already the biggest permuatation, no next exists. arrange it to ascending order.
//        sort(nums.begin(), nums.end());
//        return;
//    }
//    i--;
//    while (i < j && nums[j] <= nums[i]) {
//        j--;
//    }
//    // on right side of nums[i] exists smallest nums[j] but bigger than nums[i].
//    swap(nums[i], nums[j]);
//    // nums on right side of nums[i] just need to be sorted by ascending order.
//    sort(nums.begin() + i + 1, nums.end());
//}

void nextPermutation(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1) {
        return;
    }
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }
    if (i == -1) {
        sort(nums.begin(), nums.end());
        return;
    }
    
    int j = nums.size() - 1;
    while (j > i && nums[j] <= nums[i]) {
        j--;
    }
    swap(nums[i], nums[j]);
    sort(nums.begin()+i+1, nums.end());
}

int main(int argc, const char * argv[]) {
    vector<int> nums{1,3,2};
    nextPermutation(nums);
    for (int i=0; i<nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
