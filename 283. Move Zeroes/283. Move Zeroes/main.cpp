//
//  main.cpp
//  283. Move Zeroes
//
//  Created by Jie Lu on 2018/5/23.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0, n = (int)nums.size();
    while (j < n) {
        if (nums[j] == 0) {
            j++;
            continue;
        }
        else {
            nums[i++] = nums[j++];
        }
    }
    while (i < n) {
        nums[i++] = 0;
    }
}
int main(int argc, const char * argv[]) {
    vector<int> nums{0,1,0,3,12};
    moveZeroes(nums);
    for (auto num : nums) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
