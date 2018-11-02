//
//  main.cpp
//  75. Sort Colors
//
//  Created by Jie Lu on 2018/4/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int zero = 0, two = (int)nums.size() - 1;
    for (int i = 0; i <= two; i++) {
        while (nums[i] == 2 && i < two) {
            swap(nums[i], nums[two]);
            two--;
        }
        while (nums[i] == 0 && i > zero) {
            // i > zero condition ensures that when nums[] = {0}, it doesn't swap(nums[0], nums[0]) forever.
            swap(nums[i], nums[zero]);
            zero++;
        }
    }
}
int main(int argc, const char * argv[]) {
    int a[] = {0,1,2,1,0,2};
    vector<int> nums(a, a+6);
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    return 0;
}
