//
//  main.cpp
//  683. K Empty Slots
//
//  Created by Jie Lu on 2018/9/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int kEmptySlots(vector<int>& flowers, int k) {
    vector<int> nums(flowers.size() ,0);
    for (int i = 0; i < flowers.size(); i++) {
        nums[flowers[i] - 1] = i + 1;
    }
    
    int res = INT_MAX;
    for (int i = 0; i + k + 1 < flowers.size(); i++) {
        int maxNum = max(nums[i], nums[i+k+1]);
        int j = i + 1;
        for (; j < i + k + 1; j++) {
            if (nums[j] <= maxNum) {
                break;
            }
        }
        if (j == i + k + 1) {
            res = min(res, maxNum);
        }
    }
    return res == INT_MAX ? -1 : res;
}

int main(int argc, const char * argv[]) {
    vector<int> flowers{3,9,2,8,1,6,10,5,4,7};
    cout<<kEmptySlots(flowers, 1)<<endl;
    return 0;
}
