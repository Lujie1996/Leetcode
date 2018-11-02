//
//  main.cpp
//  869. Reordered Power of 2
//
//  Created by Jie Lu on 2018/7/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
multiset<int> convert(int num) {
    multiset<int> res;
    while (num) {
        res.insert(num % 10);
        num /= 10;
    }
    return res;
}
bool reorderedPowerOf2(int num) {
    multiset<int> numCount = convert(num);
    vector<int> powers;
    powers.push_back(1);
    int base = 1;
    while (base * 2 > base) {
        base *= 2;
        powers.push_back(base);
    }
    for (auto power : powers) {
        multiset<int> count = convert(power);
        if (count == numCount) {
            return true;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int n = 4;
    if (reorderedPowerOf2(n)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
