//
//  main.cpp
//  885. Spiral Matrix III
//
//  Created by Jie Lu on 2018/12/19.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int r,c;

bool inBox(int curR, int curC) {
    if (curR >= 0 && curR < r && curC >= 0 && curC < c) {
        return true;
    }
    else {
        return false;
    }
}

void addToRes(vector<vector<int>>& res, int R, int C) {
//    cout<<R<<" "<<C<<endl;
    if (inBox(R, C)) {
        res.push_back({R, C});
    }
}

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> res;
    int lowR, lowC, highR, highC;
    lowR = highR = r0;
    lowC = highC = c0;
    r = R;
    c = C;
    int direction = 0, n = R * C;
    int curR = r0, curC = c0;
    vector<vector<int>> steps{{0,1},{1,0},{0,-1},{-1,0}};
    
    addToRes(res, curR, curC);
    while (true) {
        if (direction == 0) {
            while (curC != highC + 1) {
                curC++;
                addToRes(res, curR, curC);
                if (res.size() == n) {
                    return res;
                }
            }
            highC++;
            direction = (direction + 1) % 4;
            continue;
        }
        if (direction == 1) {
            while (curR != highR + 1) {
                curR++;
                addToRes(res, curR, curC);
                if (res.size() == n) {
                    return res;
                }
            }
            highR++;
            direction = (direction + 1) % 4;
            continue;
        }
        if (direction == 2) {
            while (curC != lowC - 1) {
                curC--;
                addToRes(res, curR, curC);
                if (res.size() == n) {
                    return res;
                }
            }
            lowC--;
            direction = (direction + 1) % 4;
            continue;
        }
        if (direction == 3) {
            while (curR != lowR - 1) {
                curR--;
                addToRes(res, curR, curC);
                if (res.size() == n) {
                    return res;
                }
            }
            lowR--;
            direction = (direction + 1) % 4;
            continue;
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> res = spiralMatrixIII(5, 6, 1, 4);
    for (auto row : res) {
        for (auto num : row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
