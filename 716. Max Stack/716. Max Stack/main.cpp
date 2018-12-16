//
//  main.cpp
//  716. Max Stack
//
//  Created by Jie Lu on 2018/11/25.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
    stack<int> st;
    stack<int> stMax;
public:
    /** initialize your data structure here. */
    MaxStack() {
        stMax.push(INT_MIN);
    }
    
    void push(int x) {
        st.push(x);
        stMax.push(max(x, stMax.top()));
    }
    
    int pop() {
        int res = top();
        st.pop();
        stMax.pop();
        return res;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return stMax.top();
    }
    
    int popMax() {
        stack<int> tmpSt;
        while (st.top() != stMax.top()) {
            tmpSt.push(st.top());
            st.pop();
            stMax.pop();
        }
        int res = st.top();
        st.pop();
        stMax.pop();
        while (!tmpSt.empty()) {
            st.push(tmpSt.top());
            stMax.push(max(stMax.top(), st.top()));
            tmpSt.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    MaxStack ms;
    ms.push(5);
    ms.push(1);
    ms.push(-5);
    cout<<ms.popMax()<<endl;
    cout<<ms.popMax()<<endl;
    cout<<ms.top()<<endl;
    return 0;
}
