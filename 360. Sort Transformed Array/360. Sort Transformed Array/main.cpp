//
//  main.cpp
//  360. Sort Transformed Array
//
//  Created by Jie Lu on 2018/8/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
    }
    int i = 0, j = (int)nums.size() - 1, k = 0;
    if (a < 0) {
        while (i <= j) {
            if (nums[i] < nums[j]) {
                res[k++] = nums[i++];
            }
            else {
                res[k++] = nums[j--];
            }
        }
    }
    else if (a > 0) {
        k = (int)nums.size() - 1;
        while (i <= j) {
            if (nums[i] > nums[j]) {
                res[k--] = nums[i++];
            }
            else {
                res[k--] = nums[j--];
            }
        }
    }
    else {
        if (b > 0) {
            res = nums;
        }
        else {
            reverse(nums.begin(), nums.end());
            res = nums;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{-4,-2,2,4};
    vector<int> res = sortTransformedArray(nums, 0, 3, 5);
    for (auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
