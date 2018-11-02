//
//  main.cpp
//  301. Remove Invalid Parentheses
//
//  Created by Jie Lu on 2018/9/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool isValid(string& s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            count++;
        }
        else if (s[i] == ')') {
            count--;
            if (count < 0) {
                return false;
            }
        }
    }
    return count == 0;
}

// BFS solution. Tries so many possibilities, therefore not very efficient. Beats 25%.
//vector<string> removeInvalidParentheses(string s) {
//    queue<string> q;
//    q.push(s);
//
//    unordered_set<string> seen;
//    seen.insert(s);
//
//    vector<string> res;
//
//    int resLen = -1;
//
//    while (!q.empty()) {
//        string front = q.front();
//        q.pop();
//
//        if (resLen != -1 && front.size() > resLen) {
//            break;
//        }
//
//        if (isValid(front)) {
//            res.push_back(front);
//            resLen = (int)front.size();
//        }
//        if (resLen != -1) {
//            continue;
//        }
//        for (int i = 0; i < front.size(); i++) {
//            if (front[i] != '(' && front[i] != ')') {
//                continue;
//            }
//            string nextStr = front.substr(0,i) + front.substr(i+1);
//            if (seen.find(nextStr) == seen.end()) {
//                q.push(nextStr);
//                seen.insert(nextStr);
//            }
//        }
//    }
//    return res;
//}


// iterative solution
void helper(string s, int start, int cnt1, int cnt2, vector<string>& res) {
    if (cnt1 == 0 && cnt2 == 0) {
        if (isValid(s))
            res.push_back(s);
        return;
    }
    
    for (int i = start; i < s.size(); ++i) {
        if (i != start && s[i] == s[i - 1])
            continue;
        if (cnt1 > 0 && s[i] == '(') {
            helper(s.substr(0, i) + s.substr(i + 1), i, cnt1 - 1, cnt2, res);
        }
        if (cnt2 > 0 && s[i] == ')') {
            helper(s.substr(0, i) + s.substr(i + 1), i, cnt1, cnt2 - 1, res);
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    int cnt1 = 0, cnt2 = 0;
    for (char c : s) {
        cnt1 += (c == '(');
        if (cnt1 == 0)
            cnt2 += (c == ')');
        else
            cnt1 -= (c == ')');
    }
    // cnt1 and cnt2 records the relative values of count'(' and count')'
    // that is, cnt1 and cnt2 must have at least one that is 0
    helper(s, 0, cnt1, cnt2, res);
    return res;
}


int main(int argc, const char * argv[]) {
    vector<string> res = removeInvalidParentheses("()())()");
    for (auto s : res) {
        cout<<s<<endl;
    }
    return 0;
}
