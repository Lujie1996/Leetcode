//
//  main.cpp
//  287. Find the Duplicate Number
//
//  Created by Jie Lu on 2018/5/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // n+1 numbers from 1 ~ n. At first low = 1, high = n
    int low = 1, high = (int)nums.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        int count = 0;
        for (int num : nums)
            if (num <= mid)
                count++;
        if (count > mid)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main(int argc, const char * argv[]) {
    int a[] = {1,3,4,2,1};
    vector<int> nums(a, a+5);
    cout<<findDuplicate(nums)<<endl;
    return 0;
}
