//
//  main.cpp
//  66. Plus One
//
//  Created by Jie Lu on 2018/4/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = (int)digits.size();
    int i = n - 1, flag = 1;
    while (i >= 0) {
        int num = digits[i];
        digits[i] = (num + flag) % 10;
        if (num + flag == 10) {
            flag = 1;
        }
        else {
            flag = 0;
        }
        i--;
    }
    if (flag == 1) {
        vector<int> res(n+1, 0);
        res[0] = 1;
        for (i = 0; i < n; i++) {
            res[i+1] = digits[i];
        }
        return res;
    }
    return digits;
}
int main(int argc, const char * argv[]) {
    int nums[] = {9,9,9};
    vector<int> digits(nums, nums + 3);
    vector<int> res = plusOne(digits);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}
