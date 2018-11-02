//
//  main.cpp
//  402. Remove K Digits
//
//  Created by Jie Lu on 2018/5/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

// Very typical Greedy + Stack Problem. Must understand its solution.
// More similar: LC316

string removeKdigits(string num, int k) {
    if (k >= num.size()) {
        return "0";
    }
    stack<char> st;
    st.push(num[0]);
    int len = (int)num.length(), removed = 0;
    for (int i = 1; i < len; i++) {
        char c = num[i];
        while (removed < k && st.size() && st.top() > c) {
            st.pop();
            removed++;
        }
        if (c != '0' || !st.empty()) {
            // avoid pushing leading 0
            st.push(c);
        }
    }
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    res = res.substr(0, len - k);
    return res.size() == 0 ? "0" : res;
}

int main(int argc, const char * argv[]) {
    cout<<removeKdigits("1432219", 3)<<endl; // 1219
    cout<<removeKdigits("10200", 1)<<endl; // 200
    cout<<removeKdigits("10", 2)<<endl; // 0
    cout<<removeKdigits("123", 2)<<endl; // 1
    cout<<removeKdigits("0", 0)<<endl; // 0
    cout<<removeKdigits("1173", 2)<<endl; // 11
    cout<<removeKdigits("5337", 2)<<endl; // 33
    cout<<removeKdigits("100", 1)<<endl; // 0
    return 0;
}
