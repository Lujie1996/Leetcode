//
//  main.cpp
//  60. Permutation Sequence
//
//  Created by Jie Lu on 2018/4/4.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> factorial(n+1, 1); // factorial table
    vector<int> candidates(n, 0);
    string res;
    int i, fac = 1;
    for (i = 1; i <= n; i++) {
        fac *= i;
        factorial[i] = fac;
        candidates[i-1] = i;
    }
    k--;
    for(i = 1; i <= n; i++){
        int index = k / factorial[n-i];
        res += (char)('0' + candidates[index]);
        candidates.erase(candidates.begin() + index);
        k -= index*factorial[n-i];
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<getPermutation(3, 1)<<endl;
    return 0;
}
