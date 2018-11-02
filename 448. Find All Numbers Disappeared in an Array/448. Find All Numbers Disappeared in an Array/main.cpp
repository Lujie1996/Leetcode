//
//  main.cpp
//  448. Find All Numbers Disappeared in an Array
//
//  Created by Jie Lu on 2018/7/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums) {
    for (auto num : nums) {
        cout<<num<<" ";
    }
    cout<<endl;
}

/*
 The main idea is to set nums[index] to zero where index is the number that appears in nums.
 Doing this is in-place, since we are just setting present index to zero.
 see example nums: [4,3,2,7,8,2,3,1]
 1. i = 0, nums[i] is 4, so we set nums[3] to 0. (4 - 1 is in order to accommendate 1..n into 0..n-1).
 2. the previous nums[3] is 7, since we already set nums[3] to zero, now we set nums[6] to zero.
 3. keeping doing this until it's already set.
 4. every time we add 1 to i, while skipping all nums[i] == 0.
 5. when i comes to the end of nums, we just see which nums[i] does not equal to zero(that is, not set).
 */
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        while (i < nums.size() && nums[i] == 0) {
            i++;
        }
        if (i < nums.size()) {
            int j = nums[i] - 1;
            while (nums[j] != 0) {
                int t = nums[j] - 1;
                nums[j] = 0;
                j = t;
//                print(nums);
            }
            i++;
        }
    }
    vector<int> res;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            res.push_back(i+1);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{10,2,5,10,9,1,1,4,3,7};
    vector<int> res = findDisappearedNumbers(nums);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
