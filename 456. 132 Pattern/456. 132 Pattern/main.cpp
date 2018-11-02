//
//  main.cpp
//  456. 132 Pattern
//
//  Created by Jie Lu on 2018/5/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// This is not my code. Very elegant.
// Use greedy and stack is pretty common in many problems. See LC 402 & 316
bool find132pattern(vector<int>& nums) {
    // traverse the vector in reversing order
    // stack is used to track the largest number(s2)
    // every time meets a larger number nums[i], get stack top as s2 and push nums[i] to stack
    stack<int> stk;
    int s2 = INT_MIN;
    for (int i = (int)nums.size() - 1; i >= 0; --i) {
        if (nums[i] < s2)
            return true;
        while (!stk.empty() && stk.top() < nums[i]) {
            s2 = stk.top();
            stk.pop();
        }
        stk.push(nums[i]); // only push numbers that is smaller than stack top, otherwise need to uodate s2
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int a[] = {8,10,4,6,5};
    vector<int> nums(a, a+5);
    if (find132pattern(nums)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
