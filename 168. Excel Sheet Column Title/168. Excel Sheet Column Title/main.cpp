//
//  main.cpp
//  168. Excel Sheet Column Title
//
//  Created by Jie Lu on 2018/4/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int n) {
    string res;
    while(n) {
        res = (char)((n - 1) % 26 + 'A') + res;
        n = (n - 1) / 26;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n)
        cout<<convertToTitle(n)<<endl;
    return 0;
}
