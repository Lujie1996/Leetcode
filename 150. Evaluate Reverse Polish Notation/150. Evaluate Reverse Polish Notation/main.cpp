//
//  main.cpp
//  150. Evaluate Reverse Polish Notation
//
//  Created by Jie Lu on 2018/5/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    if (tokens.size() == 0) {
        return 0;
    }
    stack<string> st;
    st.push(tokens[0]);
    for (string token : tokens) {
        if (token.length() > 1 || (token[0] >= '0' && token[0] <= '9')) {
            // this token is a number
            st.push(token);
        }
        else {
            // this token is a operator
            char opt = token[0]; // operator
            int opd2 = stoi(st.top()); //operand
            st.pop();
            int opd1 = stoi(st.top());
            st.pop();
            switch (opt) {
                case '+':
                    st.push(to_string(opd1 + opd2));
                    break;
                case '-':
                    st.push(to_string(opd1 - opd2));
                    break;
                case '*':
                    st.push(to_string(opd1 * opd2));
                    break;
                case '/':
                    st.push(to_string(opd1 / opd2));
                    break;
            }
        }
    }
    return stoi(st.top());
}
int main(int argc, const char * argv[]) {
    string a[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    vector<string> tokens(a, a+13);
    cout<<evalRPN(tokens)<<endl;
    return 0;
}
