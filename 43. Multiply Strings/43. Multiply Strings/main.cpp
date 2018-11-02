//
//  main.cpp
//  43. Multiply Strings
//
//  Created by Jie Lu on 2018/4/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// My original idea. beats 25%
//string add(string num1, string num2) {
//    string res;
//    int i = (int)num1.length() - 1;
//    int j = (int)num2.length() - 1;
//    int a, b, sum, flag = 0;
//    while(i > -1 || j > -1 || flag) {
//        a = i > -1 ? num1[i] - '0' : 0;
//        b = j > -1 ? num2[j] - '0' : 0;
//        sum = a + b + flag;
//        flag = sum > 9 ? 1 : 0;
//        res = (char)(sum % 10 + '0') + res;
//        i--;
//        j--;
//    }
//    return res;
//}
//vector<string> cache(10);
//string multiplyWithOneDigit(string longNum, int oneNum, int pos) {
//    string res;
//    if (cache[oneNum] != "") {
//        res = cache[oneNum];
//    }
//    else {
//        int i, flag = 0, product;
//        i = (int)longNum.length() - 1;
//        while (i > -1 || flag) {
//            product = i > -1 ? oneNum * (longNum[i] - '0') + flag : flag;
//            flag = product > 9 ? product / 10 : 0;
//            res = (char)(product % 10 + '0') + res;
//            i--;
//        }
//        cache[oneNum] = res;
//    }
//
//    while (pos > 0) {
//        res += '0';
//        pos--;
//    }
//    return res[0] == '0' ? "0" : res;
//}
//string multiply(string num1, string num2) {
//    string res="0";
//    int n = (int)num2.length();
//    for(int i = n - 1; i >= 0; i--) {
//        string product = multiplyWithOneDigit(num1, num2[i] - '0', n - i -1);
//        res = add(res, product);
//    }
//    return res;
//}

// another faster algorithm, beats 100%
string multiply(string num1, string num2) {
    int m = (int)num1.size(), n = (int)num2.size();
    vector<int> pos(m + n);
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];
            
            pos[p1] += sum / 10;
            pos[p2] = (sum) % 10;
        }
    }
    
    string sb;
    for (int p : pos)
        if (!(sb.size() == 0 && p == 0))
            sb += p;
    return sb.size() == 0 ? "0" : sb;
}
int main(int argc, const char * argv[]) {
    string num1 = "44565656131244", num2 = "3322232221231233";
    cout<<multiply(num1, num2)<<endl;
    return 0;
}
