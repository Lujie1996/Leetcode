//
//  main.cpp
//  994. Rotting Oranges
//
//  Created by Jie Lu on 2019/8/26.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool hasOne(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout<<grid[i][j]<<" ";
            if (grid[i][j] == 1)
                return true;
        }
    }
    return false;
}

int orangesRotting(vector<vector<int>>& grid) {
    int count = 1;
    int m = grid.size(), n = grid[0].size();
    while (true) {
        auto nextGrid = grid;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (grid[i][j] == 1) {
                    if (i - 1 >= 0  && grid[i-1][j] == 2 ||
                        i + 1 < m && grid[i+1][j] == 2 ||
                        j - 1 >= 0 && grid[i][j-1] == 2 ||
                        j + 1 < n && grid[i][j+1] == 2) {
                        nextGrid[i][j] = 2;
                    }
                }
            }
        }
        if (grid == nextGrid) {
            return hasOne(nextGrid) ? -1 : count;
        }
        grid = nextGrid;
        count++;
        // return count == 0 ? -1 : count;
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid{{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(grid)<<endl;
    return 0;
}
