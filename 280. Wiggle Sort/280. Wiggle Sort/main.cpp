//
//  main.cpp
//  280. Wiggle Sort
//
//  Created by Jie Lu on 2018/6/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 This is from BBS
 If current position i is an odd number, nums[i] >= nums[i-1]
 If current position i is an even number, nums[i] <= nums[i-1]
 Only iterate once.
 To prove this is right, say there are three numbers a, b, c, and a < b < c, when goes to b, it is fine since greater than a;
 When it goes to c, number at this position should be smaller than b, so swap b and c, that is a, c, b;
 After the swap, it's easy to think that the last two numbers are in right position(swap operation is to ensure this).
 What about the first two numbers? we have:
    1. a < b (we assume the string on the left side of current position is always correct),
    2. b < c (that is why we swap them).
 Therefore we prove that c > a, meaning that by swapping b and c, we are not corrupting the correctness of previous substring.
 */
void wiggleSort(vector<int>& nums) {
    int n = (int)nums.size();
    for (int i = 1; i < n; i++)
        if (((i & 1) && nums[i] < nums[i - 1]) || (!(i & 1) && nums[i] > nums[i - 1]))
            swap(nums[i], nums[i - 1]);
}

int main(int argc, const char * argv[]) {
    vector<int> nums{3,5,2,1,6,4};
    wiggleSort(nums);
    for (auto a : nums) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
