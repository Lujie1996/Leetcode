//
//  main.cpp
//  12. Integer to Roman
//
//  Created by Jie Lu on 2018/5/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string intToRoman(int num) {
    static vector<string> ones{"","I","II","III","IV","V","VI","VII","VIII","IX"},
    tens{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    hundreds{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    thoudsands{"","M","MM","MMM"};
    static vector<vector<string>> dict{ones, tens, hundreds, thoudsands};
    string res ="";
    int i = 0;
    while (num) {
        int digit = num % 10;
        num /= 10;
        res = dict[i][digit] + res;
        i++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<intToRoman(3999)<<endl;
    return 0;
}
