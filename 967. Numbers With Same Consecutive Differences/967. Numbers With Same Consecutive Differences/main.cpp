//
//  main.cpp
//  967. Numbers With Same Consecutive Differences
//
//  Created by Jie Lu on 2019/1/3.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>

void getNum(vector<int>& res, string cur, int N, int K) {
    if (cur.size() == N) {
        res.push_back(stoi(cur));
        return;
    }
    
    int tail = cur[cur.size()-1] - '0';
    if (tail - K >= 0) {
        getNum(res, cur+to_string(tail-K), N, K);
    }
    if (K != 0 && tail + K <= 9) {
        getNum(res, cur+to_string(tail+K), N, K);
    }
}

vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> res;
    if (N == 0) {
        return res;
    }
    
    int start = N == 1 ? 0 : 1;
    for (int i = start; i <= 9; i++) {
        getNum(res, to_string(i), N, K);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
