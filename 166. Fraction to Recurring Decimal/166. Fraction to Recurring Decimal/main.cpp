//
//  main.cpp
//  166. Fraction to Recurring Decimal
//
//  Created by Jie Lu on 08/03/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    long long num = numerator, den = denominator;
    //必须用long long，否则会溢出。例如：INT_MIN/-1
    string res;
    if((double)num/den<0){
        res += '-';
    }
    num = abs(num);
    den = abs(den);
    res += to_string(num/den);
    long long remain = num % den;
    //必须是long long，例如: -1/INT_MIN，remain会一直增长到100000000000（比INT_MIN多一位）
    if(remain == 0) {
        return res;
    }
    res += '.';
    unordered_map<long long, int> map; //map<remain, position>
    int pos = (int)res.find('.')+1;
    remain = abs(remain);
    while(true) {
        if(remain == 0){
            return res;
        }
        if(map.find(remain)!=map.end()){
            res.insert(map[remain], "(");
            res += ')';
            return res;
        }
        else{
            map[remain] = pos;
        }
        remain *= 10;
        res += to_string(remain / den);
        if(remain > den)
            remain = remain % den;
        pos++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int numerator, denominator;
    while (cin>>numerator>>denominator) {
        cout<<fractionToDecimal(numerator, denominator);
    }
    return 0;
}
