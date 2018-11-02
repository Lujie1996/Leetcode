//
//  main.cpp
//  232. Implement Queue using Stacks
//
//  Created by Jie Lu on 2018/5/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// This is my original solution.
//class MyQueue {
//private:
//    stack<int> st;
//public:
//    /** Initialize your data structure here. */
//    MyQueue() {
//
//    }
//
//    /** Push element x to the back of queue. */
//    void push(int x) {
//        vector<int> tmp(st.size(), 0);
//        int i = 0;
//        while (!st.empty()) {
//            tmp[i++] = st.top();
//            st.pop();
//        }
//        st.push(x);
//        while (i) {
//            st.push(tmp[--i]);
//        }
//    }
//
//    /** Removes the element from in front of queue and returns that element. */
//    int pop() {
//        int res = st.top();
//        st.pop();
//        return res;
//    }
//
//    /** Get the front element. */
//    int peek() {
//        return st.top();
//    }
//
//    /** Returns whether the queue is empty. */
//    bool empty() {
//        return st.empty();
//    }
//};

// Some other guy's solution using two stacks
class MyQueue {
private:
    stack<int> input, output;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = peek();
        output.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};
int main(int argc, const char * argv[]) {
    MyQueue obj = MyQueue();
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout<<obj.peek()<<endl;
    obj.pop();
    cout<<obj.peek()<<endl;
    return 0;
}
