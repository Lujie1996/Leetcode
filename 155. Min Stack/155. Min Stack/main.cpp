//
//  main.cpp
//  155. Min Stack
//
//  Created by Jie Lu on 2018/4/25.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<int> a;
    vector<int> min;
    MinStack() {
        min.push_back(INT_MAX);
    }
    void push(int x) {
        a.push_back(x);
        if (x < min.back()) {
            min.push_back(x);
        } else {
            min.push_back(min.back());
        }
    }
    
    void pop() {
        a.pop_back();
        min.pop_back();
    }
    
    int top() {
        return a.back();
    }
    
    int getMin() {
        return min.back();
    }
};

int main(int argc, const char * argv[]) {
    MinStack* ms = new MinStack();
    ms->push(2);
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->top()<<endl;
    return 0;
}
