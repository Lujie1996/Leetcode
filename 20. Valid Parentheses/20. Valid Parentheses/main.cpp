//
//  main.cpp
//  20. Valid Parentheses
//
//  Created by Jie Lu on 2019/9/5.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;


bool isValid(string s) {
    stack<char> stk;
    for (auto c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        }
        else {
            if (stk.empty()) {
                return false;
            }
            if (c == ')') {
                if (stk.top() == '(') {
                    stk.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
            else if (c == ']') {
                if (stk.top() == '[') {
                    stk.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                if (stk.top() == '{') {
                    stk.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
        }
    }
    return stk.empty();
}

int main(int argc, const char * argv[]) {
    cout<<isValid("()[]{}")<<endl;
    return 0;
}
