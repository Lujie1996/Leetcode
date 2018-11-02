//
//  main.cpp
//  394. Decode String
//
//  Created by Jie Lu on 2018/5/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

string decodeString(string s) {
    if (s.length() == 0) {
        return "";
    }
    stack<char> st;
    st.push(s[0]);
    int i = 1, len = (int)s.length();
    while (i < len) {
        char c = s[i];
        if (isdigit(c) ||isalpha(c) || c == '[') {
            st.push(c);
        }
        else {
            // c == ']'
            string encode;
            while (st.top() != '[') {
                encode = st.top() + encode;
                st.pop();
            }
            st.pop(); // pop '['
            int k = 0, base = 1;
            while (!st.empty() && isdigit(st.top())) {
                k += (st.top() - '0')* base;
                st.pop();
                base *= 10;
            }
            for (int j = 0; j < k; j++) {
                for (int a = 0; a < encode.length(); a++) {
                    st.push(encode[a]);
                }
            }
        }
        i++;
    }
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<decodeString("3[a2[c]]ef")<<endl;
    return 0;
}
