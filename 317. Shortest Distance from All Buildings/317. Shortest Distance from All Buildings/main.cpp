//
//  main.cpp
//  317. Shortest Distance from All Buildings
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tryBuildHere(vector<vector<int>>& grid, int i, int j, int noOfOnes) {
    int path = 0, curLen = 0;
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    
    queue<pair<int,int>> q;
    q.push({i,j});
    q.push({-1,-1});
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
    visited[i][j] = true;
    
    int countOnes = 0;
    
    while (!q.empty()) {
        pair<int,int> top = q.front();
        q.pop();
        if (top.first == -1) {
            curLen += 1;
            if (!q.empty()) {
                q.push({-1,-1});
            }
            continue;
        }
        
        int row = top.first, col = top.second;
        
        for (int k = 0; k < 4; k++) {
            int nextI = row + directions[k][0];
            int nextJ = col + directions[k][1];
            if (nextI >= 0 && nextI < grid.size() && nextJ >= 0 && nextJ < grid[0].size() && !visited[nextI][nextJ]) {
                visited[nextI][nextJ] = true;
                if (grid[nextI][nextJ] == 0) {
                    q.push({nextI, nextJ});
                }
                else if (grid[nextI][nextJ] == 1) {
                    path += (curLen + 1);
                    countOnes += 1;
                }
            }
        }
    }
    
    return countOnes == noOfOnes ? path : -1;
}

int shortestDistance(vector<vector<int>>& grid) {
    if (grid.size() == 0) {
        return -1;
    }
    
    int minPath = INT_MAX;
    bool existOne = false;
    
    int noOfOnes = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                noOfOnes += 1;
            }
        }
    }
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                int thisPath = tryBuildHere(grid, i, j, noOfOnes);
                if (thisPath != -1) {
                    existOne = true;
                    minPath = min(minPath, thisPath);
                }
            }
        }
    }
    
    return existOne ? minPath : -1;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid{{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    cout<<shortestDistance(grid)<<endl;
    return 0;
}
