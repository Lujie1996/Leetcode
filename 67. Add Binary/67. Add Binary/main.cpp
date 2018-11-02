//
//  main.cpp
//  67. Add Binary
//  这道题和LC2 Add Two Numbers很相似，那道题是十进制相加，链表实现
//
//  Created by Jie Lu on 2018/4/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    int i = (int)a.length() - 1, j = (int)b.length() - 1, flag = 0, num1, num2, sum;
    string res;
    while (i >= 0 || j >=0 || flag) {
        // 判断条件不能写 while (i || j || flag)，因为当 i = -1， while将 -1 判断为true（只有 0 会被判false）
        num1 = i >= 0 ? a[i--] - '0' : 0;
        num2 = j >= 0 ? b[j--] - '0' : 0;
        sum = num1 + num2 + flag;
        if (sum >= 2) {
            flag = 1;
            sum %= 2;
        }
        else
            flag = 0;
        res = (char)('0' + sum) + res;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<addBinary("1111", "1111")<<endl;
    return 0;
}
