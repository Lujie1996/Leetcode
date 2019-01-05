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

//int search(vector<int>& nums, int target) {
//    if (nums.size() == 0) {
//        return -1;
//    }
//    int low = 0, high = (int)nums.size() - 1;
//    while (low < high) {
//        int mid = low + (high - low) / 2;
//        if (target < nums[low]) {
//            if (nums[mid] >= nums[low]) {
//                low = mid + 1;
//            }
//            else {
//                if (nums[mid] < target) {
//                    low = mid + 1;
//                }
//                else if (nums[mid] > target) {
//                    high = mid;
//                }
//                else {
//                    return mid;
//                }
//            }
//        }
//        else  if (target > nums[low]) {
//            if (nums[mid] < nums[low]) {
//                high = mid;
//            }
//            else {
//                if (nums[mid] < target) {
//                    low = mid + 1;
//                }
//                else if (nums[mid] > target) {
//                    high = mid;
//                }
//                else {
//                    return mid;
//                }
//            }
//        }
//        else {
//            return low;
//        }
//    }
//    return nums[low] == target ? low : -1;
//}

// solution 2018/12/30
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, mid = 0;
    while (low <= high) { // note: <= not <
        mid = (low + high) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        
        // left part is ordered (nums[0..mid] is ordered, including nums[mid])
        if (nums[mid] >= nums[low]) {
            // >=不是>,很重要！当有两个数的时候，上一步没return就说明target!=nums[mid]，target==nums[high]
            // 在[3,1] target=1的例子里，如果不是>=就会进入else从而从high变成0，跳过了正确的范围
            // 并且，在[1] target=1的例子里，如果不是>=就会进入else的else里面，high=mid会让low永远等于high
            if (target >= nums[low] && target < nums[mid]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{3,1};
    cout<<search(nums,1)<<endl;
    return 0;
}
