//
//  main.cpp
//  540. Single Element in a Sorted Array
//
//  Created by Jie Lu on 2018/7/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = (int)nums.size() - 1, mid = 0;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == nums[mid+1]) {
            mid--;
        }
        if ((mid - low) % 2 == 0) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return nums[low];
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,1,3,3,4,4,7,8,8};
    cout<<singleNonDuplicate(nums)<<endl;
    return 0;
}
