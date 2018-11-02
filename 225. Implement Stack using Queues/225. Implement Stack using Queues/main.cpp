//
//  main.cpp
//  225. Implement Stack using Queues
//
//  Created by Jie Lu on 2018/5/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
int main(int argc, const char * argv[]) {
    MyStack obj = MyStack();
    obj.push(4);
    obj.push(2);
    cout<<obj.top()<<endl;
    obj.pop();
    cout<<obj.top()<<endl;
    obj.pop();
//    obj.push(1);
    if (obj.empty()) {
        cout<<"empty"<<endl;
    }
    else {
        cout<<"not empty"<<endl;
    }
    return 0;
}
