//
//  main.cpp
//  277. Find the Celebrity
//
//  Created by Jie Lu on 2018/6/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> know{{1,1},{0,1}};
bool knows(int a, int b) {
    return know[a][b] == 1;
}

// This is my original solution. Beats 65%.
// 1. Find a possibleCelebrity who does not know any other person;
// 2. Check if everyone else knows this possibleCelebrity.
int findCelebrity(int n) {
    vector<int> dontKnowOthers;
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (knows(i, j)) {
                break;
            }
        }
        if (j == n) {
            for (k = 0; k < n; k++) {
                if (i == k) {
                    continue;
                }
                if (!knows(k, i)) {
                    break;
                }
            }
            if (k == n) {
                return i;
            }
        }
    }
    return -1;
}

// This solution is from BBS. It has easier implementation, but only beats 30%.
//int findCelebrity(int n) {
//    int i, j;
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            if (i != j && knows(i, j))
//                break; //if i knows j, i is not celebrity
//            if (i != j && !knows(j, i))
//                break; //if j don't know i, not celebrity
//        }
//        if (j == n)
//            return i; //i does not know any j , but all j know i
//    }
//    return -1;
//}
int main(int argc, const char * argv[]) {
    cout<<findCelebrity(2)<<endl;
    return 0;
}
