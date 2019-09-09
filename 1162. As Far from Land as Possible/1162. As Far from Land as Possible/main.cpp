//
//  main.cpp
//  1162. As Far from Land as Possible
//
//  Created by Jie Lu on 2019/8/28.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int maxDistance(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                q.push({i-1, j});
                q.push({i+1, j});
                q.push({i, j-1});
                q.push({i, j+1});
            }
        }
    }
    int steps = 1;
    q.push({-10,-10});
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        if (front.first == -10) {
            steps += 1;
            cout<<"----- new loop -----"<<endl;
            if (!q.empty()) {
                q.push({-10,-1});
            }
            continue;
        }
        int i = front.first;
        int j = front.second;
        
        if (i >= 0 && i < m && j >=0 && j < n && grid[i][j] == 0) {
            cout<<i<<" "<<j<<" "<<steps<<endl;
            grid[i][j] = steps;
            q.push({i-1, j});
            q.push({i+1, j});
            q.push({i, j-1});
            q.push({i, j+1});
        }
    }
    return steps == 2 ? -1 : steps - 2;
}

int main(int argc, const char * argv[]) {
//    vector<vector<int>> grid{{0,0,1,1,1},{0,1,1,0,0},{0,0,1,1,0},{1,0,0,0,0},{1,1,0,0,1}};
    vector<vector<int>> grid{{1,0,1},{0,0,0},{1,0,1}};
    cout<<maxDistance(grid)<<endl;
    return 0;
}
