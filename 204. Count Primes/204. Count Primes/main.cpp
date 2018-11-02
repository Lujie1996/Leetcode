//
//  main.cpp
//  204. Count Primes
//
//  Created by Jie Lu on 2018/4/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// Algorithm: https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95
// Sieve of Eratosthenes 埃拉托斯特尼筛法
int countPrimes(int n) {
    vector<bool> passed(n, false);
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (passed[i]) {
            continue;
        }
        for (int j = 2 * i; j < n; j += i) {
            passed[j] = true;
        }
    }
    for (int i = 2; i < n; i++) {
        if (!passed[i]) {
            count += 1;
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    cout<<countPrimes(10)<<endl;
    return 0;
}
