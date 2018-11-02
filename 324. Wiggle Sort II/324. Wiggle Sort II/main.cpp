//
//  main.cpp
//  324. Wiggle Sort II
//
//  Created by Jie Lu on 2018/7/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void wiggleSort(vector<int>& nums) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    for (int i = (int)nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--) {
        if (i & 1) {
            nums[i] = sorted[k++];
        }
        else {
            nums[i] = sorted[j++];
        }
    }
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,5,3,1,2,3,3,1,3,4};
    wiggleSort(nums);
    for (auto num : nums) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
