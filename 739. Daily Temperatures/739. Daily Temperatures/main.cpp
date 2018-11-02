//
//  main.cpp
//  739. Daily Temperatures
//
//  Created by Jie Lu on 2018/6/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Very similar to Next Greater Element II
// Use stack. Traverse the input vector, if current number > stk.top(), then push current number;
// Otherwise keep popping from stk until it meets one number which is greater than current number.
// Use stack<pair<int, int>> to store more information.
// The first int represents for the index of day, the second represents for the temperature at that day.
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    stack<pair<int, int>> stk;
    for (int i = 0; i < temperatures.size(); i++) {
        while (!stk.empty() && temperatures[i] > stk.top().second) {
            res[stk.top().first] = i - stk.top().first;
            stk.pop();
        }
        stk.push(make_pair(i, temperatures[i]));
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> a{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(a);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
