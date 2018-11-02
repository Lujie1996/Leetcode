//
//  main.cpp
//  633. Sum of Square Numbers
//
//  Created by Jie Lu on 2018/8/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_set>
using namespace std;

// Too slow, beats only 7%
//bool judgeSquareSum(int c) {
//    unordered_set<int> sqrNums;
//    int i = 0;
//    while (true) {
//        int sqrNum = i * i;
//        i++;
//        if (sqrNum >= 0 && sqrNum <= c) {
//            sqrNums.insert(sqrNum);
//        }
//        else {
//            break;
//        }
//    }
//    for (auto sqrNum : sqrNums) {
//        if (sqrNums.find(c - sqrNum) != sqrNums.end()) {
//            return true;
//        }
//    }
//    return false;
//}

// Beats 80%. Very intuitive idea.
//bool judgeSquareSum(int c) {
//    for (long a = 0; a*a <= c; a++) {
//        double b = sqrt(c-a*a);
//        if (b == (int)b) {
//            return true;
//        }
//    }
//    return false;
//}

// Very smart two pointer idea. Beats 100%
bool judgeSquareSum(int c) {
    if (c < 0)
        return false;
    int left = 0, right = sqrt(c);    // When left = 0, right can be at most sqrt(c).
    while (left <= right) {
        int current = left * left + right * right;
        if (current < c) {
            ++left;
        }
        else if (current > c) {
            --right;
        }
        else {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    if (judgeSquareSum(3)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
