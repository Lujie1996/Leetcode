//
//  main.cpp
//  454. 4Sum II
//
//  Created by Jie Lu on 2018/7/20.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int res = 0;
    unordered_map<int, int> abSum;
    for (auto a : A) {
        for (auto b: B) {
            abSum[a+b] += 1;
        }
    }
    for (auto c : C) {
        for (auto d : D) {
            auto it = abSum.find(0 - c - d);
            if (it != abSum.end()) {
                res += it->second;
            }
            
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    /*
     A = [ 1, 2]
     B = [-2,-1]
     C = [-1, 2]
     D = [ 0, 2]
     */
    vector<int> A{1,2}, B{-2,-1}, C{-1,2}, D{0,2};
    cout<<fourSumCount(A, B, C, D)<<endl;
    return 0;
}
