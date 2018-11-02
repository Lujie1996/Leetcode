//
//  main.cpp
//  547. Friend Circles
//
//  Created by Jie Lu on 2018/6/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& M, vector<bool>& connected, int no, int& count) {
    connected[no] = true;
    count++;
    for (int i = 0; i < M.size(); i++) {
        if (M[no][i] == 1 && !connected[i]) {
            DFS(M, connected, i, count);
        }
    }
}
int findCircleNum(vector<vector<int>>& M) {
    int n = (int)M.size(), count = 0, res = 0;
    vector<bool> connected(n, false);
    for (int i = 0; i < n; i++) {
        if (connected[i]) {
            continue;
        }
        DFS(M, connected, i, count);
        res++;
        if (res == n) {
            break;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> a{1,0,0,1}, b{0,1,1,0}, c{0,1,1,1}, d{1,0,1,1};
    vector<vector<int>> M{a,b,c,d};
    cout<<findCircleNum(M)<<endl;
    return 0;
}
