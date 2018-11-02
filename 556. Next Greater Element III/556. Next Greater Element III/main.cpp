//
//  main.cpp
//  556. Next Greater Element III
//
//  Created by Jie Lu on 2018/5/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// This problem is very similary to Next Permutation.
// The difference is that this problem requires to check if the nextGreaterELement overflows.
bool ifOverFlow(vector<int>& num) {
    string s;
    for (auto digit : num) {
        s += to_string(digit);
    }
    return s > "2147483647";
}
int nextGreaterElement(int n) {
    vector<int> num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    reverse(num.begin(), num.end());
    int i = (int)num.size() - 2;
    while (i >= 0 && num[i] >= num[i+1]) {
        i--;
    }
    if (i == -1) {
        return -1;
    }
    int j = (int)num.size() - 1;
    while (j > i && num[j] <= num[i]) {
        j--;
    }
    int tmp = num[i];
    num[i] = num[j];
    num[j] = tmp;
    sort(num.begin() + i + 1, num.end());
    if (num.size() == 10 && ifOverFlow(num)) {
        return -1;
    }
    int base = 1, res = 0;
    for (int i = (int)num.size() - 1; i >= 0; i--) {
        res += base * num[i];
        base *= 10;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<nextGreaterElement(13)<<endl;
    return 0;
}
