//
//  main.cpp
//  772. Basic Calculator III
//
//  Created by Jie Lu on 2018/9/18.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int parseNum(string& s, int& i) {
    int n = 0;
    while(i < s.length() && isdigit(s[i]))
        n = s[i++] - '0' + 10 * n;
    return n;
}

int parseExpr(string& s, int& i) {
    vector<int> nums;
    char op = '+';
    for (; i < s.length() && op != ')'; i++) {
        if (s[i] == ' ') continue;
        int n = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
        switch(op) {
            case '+' : nums.push_back(n); break;
            case '-' : nums.push_back(-n); break;
            case '*' : nums.back() *= n; break;
            case '/' : nums.back() /= n; break;
        }
        op = s[i];
    }
    int res = 0;
    for (int n : nums) res += n;
    return res;
}

int calculate(string s) {
    int i = 0;
    return parseExpr(s, i);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
