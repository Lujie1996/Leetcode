//
//  main.cpp
//  496. Next Greater Element I
//
//  Created by Jie Lu on 2018/5/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// This is my first solution. Record index of every number in nums; For every number in findNums,
// first get its index in nums and then search from that position.
//vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
//    unordered_map<int, int> numIndex;
//    int i,j;
//    for (i = 0; i < nums.size(); i++) {
//        numIndex[nums[i]] = i;
//    }
//    vector<int> res;
//    for (i = 0; i < findNums.size(); i++) {
//        for (j = numIndex[findNums[i]]; j < nums.size(); j++) {
//            if (nums[j] > findNums[i]) {
//                res.push_back(nums[j]);
//                break;
//            }
//        }
//        if (j == nums.size()) {
//            res.push_back(-1);
//        }
//    }
//    return res;
//}

// This is my second solution.
// Just traverse the nums and use a map to record the next for every number in it.
// When returning, just fetch the next of the required ones.
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    // Maintain a stack to record all numbers that don't have a next yet. Note that numbers in stack are in desecnding order.
    // Once comes a big number, constantly try stack top to see if it could be the next for it.
    stack<int> st;
    unordered_map<int, int> next;
    for (auto num : nums) {
        while (!st.empty() && num > st.top()) {
            next[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }
    vector<int> res;
    for (auto num : findNums) {
        int thisNext = next[num] == 0 ? -1 : next[num];
        res.push_back(thisNext);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int a[] = {4,1,2};
    int b[] = {1,3,4,2};
    vector<int> findNums(a, a+3);
    vector<int> nums(b, b+4);
    vector<int> res = nextGreaterElement(findNums, nums);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
