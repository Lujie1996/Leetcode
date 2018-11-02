//
//  main.cpp
//  503. Next Greater Element II
//
//  Created by Jie Lu on 2018/5/26.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<pair<int, int>> st;
    vector<int> res(nums.size(), -1);
    for (int i = 0; i < 2 * nums.size(); i++) {
        int t = i % nums.size();
        while (!st.empty() && st.top().second < nums[t]) {
            res[st.top().first] = nums[t];
            st.pop();
        }
        st.push(make_pair(t, nums[t]));
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,2,3,4,3};
    vector<int> res = nextGreaterElements(nums);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
