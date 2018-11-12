//
//  main.cpp
//  239. Sliding Window Maximum
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // dp stores the index, the front number in dp is the largest number in window
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() == i-k)
            dq.pop_front(); // queue front is too far away, exceeds the window size
        
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        
        dq.push_back(i);
        if (i >= k-1)
            res.push_back(nums[dq.front()]);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(nums, 3);
    for (auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
