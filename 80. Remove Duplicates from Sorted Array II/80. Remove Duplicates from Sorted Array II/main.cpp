//
//  main.cpp
//  80. Remove Duplicates from Sorted Array II
//
//  Created by Jie Lu on 2018/4/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// This is code for 26. Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int i = 0, j = 0, rightBound = (int)nums.size() - 1;
    nums.push_back(nums[0] - 1);
    while (j <= rightBound) {
        while (j <= rightBound && nums[j] != nums[j+1]) {
            nums[i++] = nums[j++];
        }
        while (j <= rightBound && nums[j] == nums[j+1]) {
            j++;
        }
    }
    return i;
}

//Another implementation based on the same idea but is much more concise:
//int removeDuplicates(vector<int>& nums) {
//    int i = 0;
//    for (int n : nums)
//        if (!i || n > nums[i-1])
//            nums[i++] = n;
//    return i;
//}

//--------------------------------------------------------------------------------
// This is code for 80. Remove Duplicates from Sorted Array II
// Idea: two pointers
// j runs faster then i. i tracks the right-side boudary of result array, j runs ahead to move valid nums to nums[i]
// [0, 0, 1, 3, 3, 7, 7, 7, 7, 8, 9, 10, ...]
//                       i     j

//int removeDuplicates(vector<int>& nums) {
//    if (nums.size() == 0) {
//        return 0;
//    }
//    int i = 0, j = 0, rightBound = (int)nums.size() - 1;
//    nums.push_back(nums[0] - 1);
//    while (j <= rightBound) {
//        while (j <= rightBound && nums[j] != nums[j+1]) {
//            nums[i++] = nums[j++];
//        }
//        if (j < rightBound) {
//            nums[i++] = nums[j++];
//        }
//        while (j <= rightBound && nums[j] == nums[j+1]) {
//            j++;
//        }
//    }
//    return i;
//}

//Following the second solution in LC 26, a better and more concise way to implement:
//int removeDuplicates(vector<int>& nums) {
//    int i = 0;
//    for (int n : nums)
//        if (i < 2 || n > nums[i-2])
//            nums[i++] = n;
//    return i;
//}
int main(int argc, const char * argv[]) {
    int a[] = {1,2,2,2,3,3,4};
    vector<int> nums(a,a+6);
    cout<<removeDuplicates(nums)<<endl;
    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
