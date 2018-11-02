//
//  main.cpp
//  215. Kth Largest Element in an Array
//
//  Created by Jie Lu on 2018/4/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//int findKthLargest(vector<int>& nums, int k) {
//    priority_queue<int> maxHeap(nums.begin(), nums.end());
//    for (int i = 0; i < k - 1; i++) {
//        maxHeap.pop();
//    }
//    return maxHeap.top();
//}
void printArrary(vector<int>& nums) {
    for (auto num : nums) {
        cout<<num<<" ";
    }
    cout<<endl;
}
int quickSortPartition(vector<int>& nums, int start, int end) {
    int low = start, high = end, pivot = nums[start];
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}
int findInRange(vector<int>& nums, int k, int start, int end) {
    if (start == end) {
        return nums[start];
    }
    int pivotIndex = quickSortPartition(nums, start, end);
    int pivotRank = end - pivotIndex + 1;
    if (pivotRank == k) {
        return nums[pivotIndex];
    }
    else if (pivotRank > k) {
        return findInRange(nums, k, pivotIndex + 1, end);
    }
    else {
        return findInRange(nums, k - pivotRank, start, pivotIndex - 1);
    }
}
int findKthLargest(vector<int>& nums, int k) {
    return findInRange(nums, k, 0, (int)nums.size()-1);
}
int main(int argc, const char * argv[]) {
    vector<int> nums{2,1};
    cout<<findKthLargest(nums, 2)<<endl;
    return 0;
}
