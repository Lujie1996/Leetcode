//
//  main.cpp
//  227. Basic Calculator II
//
//  Created by Jie Lu on 2018/5/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

// My code below, which is very very slow.
// Actually I just figured out why it is so slow. This code is literally the slowest, which takes more than 1800ms,
// and most other people's submissions only take less than 50ms.
// The reason is simple: in function getANum, don't pass arg string s by value, pass it by reference.
// Since some test cases have very very very long string as input, pass by value takes 99.9% of test time.
int getANum(string& s, int& i) {
    int num = 0, len = (int)s.length();
    while (i < len) {
        char c = s[i];
        if (c == ' ') {
            i++;
            continue;
        }
        if (c >= '0') {
            num = num * 10 + c - '0';
            i++;
        }
        else
            break;
    }
    return num;
}
int calculate(string s) {
    int i = 0, len = (int)s.length(), res = 0, sign = 1, preVal = 0;
    char c;
    while (i < len) {
        c = s[i];
        if (c == ' ') {
            i++;
            continue;
        }
        if (c >= '0') {
            preVal = getANum(s, i);
        }
        else if (c == '+') {
            res += sign * preVal;
            sign = 1;
            i++;
        }
        else if (c == '-'){
            res += sign * preVal;
            sign = -1;
            i++;
        }
        else if (c == '*' || c == '/') {
            i++;
            int a = getANum(s, i);
            if (c == '*') {
                preVal = preVal * a;
            }
            else
            {
                preVal = preVal / a;
            }
        }
    }
    res += sign * preVal;
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<calculate("12-3*4")<<endl; // 0
    cout<<calculate("12-3-4")<<endl; // 5
    cout<<calculate("2*3-4")<<endl; // 2
    cout<<calculate("0*0")<<endl; // 2
    return 0;
}
