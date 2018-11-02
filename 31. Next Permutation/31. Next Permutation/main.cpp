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

void nextPermutation(vector<int>& nums) {
    int i, j;
    i = j = (int)nums.size() - 1;
    // iterate from right to left, see where breaks the ascending order.
    while (i > 0 && nums[i-1] >= nums[i]) {
        i--;
    }
    if (i == 0) {
        // already the biggest permuatation, no next exists. arrange it to ascending order.
        sort(nums.begin(), nums.end());
        return;
    }
    i--;
    while (i < j && nums[j] <= nums[i]) {
        j--;
    }
    // on right side of nums[i] exists smallest nums[j] but bigger than nums[i].
    swap(nums[i], nums[j]);
    // nums on right side of nums[i] just need to be sorted by ascending order.
    sort(nums.begin() + i + 1, nums.end());
}
int main(int argc, const char * argv[]) {
    int a[] = {1,5,1};
    vector<int> nums(a, a+3);
    nextPermutation(nums);
    for (int i=0; i<nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
