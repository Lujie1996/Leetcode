//
//  main.cpp
//  415. Add Strings
//
//  Created by Jie Lu on 2018/7/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

string addStrings(string num1, string num2) {
    int flag = 0, i = (int)num1.size() - 1, j = (int)num2.size() - 1;
    string res;
    while (flag || i >= 0 || j >= 0) {
        int a = i >= 0 ? num1[i--] - '0' : 0, b = j >= 0 ? num2[j--] - '0' : 0;
        int sum = a + b + flag;
        res += to_string(sum % 10);
        flag = sum > 9 ? 1 : 0;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<addStrings("1237", "2234")<<endl;
    return 0;
}
