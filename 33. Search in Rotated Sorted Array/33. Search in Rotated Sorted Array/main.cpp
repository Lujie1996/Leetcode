//
//  main.cpp
//  33. Search in Rotated Sorted numsrray
//
//  Created by Jie Lu on 2018/8/18.
//  Copyright © 2018 Jie Lu. numsll rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    int low = 0, high = (int)nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (target < nums[low]) {
            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            }
            else {
                if (nums[mid] < target) {
                    low = mid + 1;
                }
                else if (nums[mid] > target) {
                    high = mid;
                }
                else {
                    return mid;
                }
            }
        }
        else  if (target > nums[low]) {
            if (nums[mid] < nums[low]) {
                high = mid;
            }
            else {
                if (nums[mid] < target) {
                    low = mid + 1;
                }
                else if (nums[mid] > target) {
                    high = mid;
                }
                else {
                    return mid;
                }
            }
        }
        else {
            return low;
        }
    }
    return nums[low] == target ? low : -1;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{3,1};
    cout<<search(nums,1)<<endl;
    return 0;
}
