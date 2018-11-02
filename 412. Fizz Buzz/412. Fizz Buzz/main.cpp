//
//  main.cpp
//  412. Fizz Buzz
//
//  Created by Jie Lu on 2018/7/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> res(n);
    int a = n / 3, b = n / 5;
    for (int i = 1; i <= a; i++) {
        res[i * 3 - 1] += "Fizz";
    }
    for (int i = 1; i <= b; i++) {
        res[i * 5 - 1] += "Buzz";
    }
    for (int i = 1; i <= n; i++) {
        if (res[i - 1].size() == 0) {
            res[i - 1] = to_string(i);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> res = fizzBuzz(3);
    for (auto s : res) {
        cout<<s<<endl;
    }
    return 0;
}
