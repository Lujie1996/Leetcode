//
//  main.cpp
//  316. Remove Duplicate Letters
//
//  Created by Jie Lu on 2018/5/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

string removeDuplicateLetters(string s) {
    unordered_map<char, int> charCount, included;
    for (char c : s) {
        charCount[c] += 1;
    }
    stack<char> st;
    for (char c : s) {
        charCount[c] -= 1;
        if (included[c])
            continue;
        // consider acdc..., when i comes to 3, acd < adc, deleting provious 'c' makes its alphabetic order larger since it elevates the position of later 'd'
        
        //if current character is smaller than last character in stack which occurs later in the string again
        //it can be removed and added later e.g stack = bc remaining string abc then a can pop b and c
        while(!st.empty() && c < st.top() && charCount[st.top()] != 0){
            included[st.top()] = 0;
            st.pop();
        }
        st.push(c);
        included[c] = 1;
    }
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<removeDuplicateLetters("cbacdcbc")<<endl;
    return 0;
}
