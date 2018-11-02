//
//  main.cpp
//  728. Self Dividing Numbers
//
//  Created by Jie Lu on 2018/7/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    for (int i = left; i <= right; i++) {
        int num = i;
        if (num == 21) {
            
        }
        while (num) {
            int digit = num % 10;
            if (digit == 0 || i % digit != 0) {
                break;
            }
            num /= 10;
        }
        if (num == 0) {
            res.push_back(i);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> res = selfDividingNumbers(1, 21);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
