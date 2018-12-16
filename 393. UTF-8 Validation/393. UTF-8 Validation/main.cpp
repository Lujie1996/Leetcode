//
//  main.cpp
//  393. UTF-8 Validation
//
//  Created by Jie Lu on 2018/12/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool getOneChar(vector<int>& data, int& pos) {
    int init = data[pos];
    if ((init & 0b10000000) == 0) {
        // first bit is 0
        return true;
    }
    
    if ((init & 0b11000000) == 0b10000000) {
        // first two-bit is 10
        return false;
    }
    
    int cnt = 0;
    // number of leading 1s
    while (init & 0b10000000) {
        cnt++;
        init <<= 1;
    }
    if (cnt > 4) {
        return false;
    }
    
    for (int i = 0; i < cnt - 1; i++) {
        if (++pos < data.size() && (data[pos] & 0b11000000) == 0b10000000) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

bool validUtf8(vector<int>& data) {
    int i = 0;
    while (i < data.size()) {
        if (!getOneChar(data, i)) {
            return false;
        }
        i++;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{115,100,102,231,154,132,13,10};
    /*
     0b01110011
     0b01100100
     0b01100110
     0b11100111
     0b10011010
     0b10000100
     0b00001101
     0b00001010
     */
    cout<<validUtf8(nums)<<endl;
    return 0;
}
