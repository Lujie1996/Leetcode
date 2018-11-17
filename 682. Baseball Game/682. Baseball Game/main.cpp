//
//  main.cpp
//  682. Baseball Game
//
//  Created by Jie Lu on 2018/11/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int calPoints(vector<string>& ops) {
    stack<int> st;
    for (auto op : ops) {
        if (op == "C") {
            st.pop();
        }
        else if (op == "D") {
            st.push(2 * st.top());
        }
        else if (op == "+") {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.push(first);
            st.push(first + second);
        }
        else {
            st.push(stoi(op));
        }
    }
    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
