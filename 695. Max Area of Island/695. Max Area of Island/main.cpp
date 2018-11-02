//
//  main.cpp
//  695. Max Area of Island
//
//  Created by Jie Lu on 2018/7/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int dfsCountAreas(vector<vector<int>>& grid, vector<vector<bool>>& visited, int cur, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) {
        return cur;
    }
    else {
        visited[i][j] = true;
        cur += 1;
        int a = dfsCountAreas(grid, visited, 0, i, j+1);
        int b = dfsCountAreas(grid, visited, 0, i+1, j);
        int c = dfsCountAreas(grid, visited, 0, i, j-1);
        int d = dfsCountAreas(grid, visited, 0, i-1, j);
        return a + b + c + d + 1;
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                res = max(res, dfsCountAreas(grid, visited, 0, i, j));
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> grid{{1,1,0,0,0},
                             {1,1,0,0,0},
                             {0,0,0,1,1},
                             {0,0,0,1,1},
    };
    cout<<maxAreaOfIsland(grid)<<endl;
    return 0;
}
