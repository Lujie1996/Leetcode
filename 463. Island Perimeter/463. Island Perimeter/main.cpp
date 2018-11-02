//
//  main.cpp
//  463. Island Perimeter
//
//  Created by Jie Lu on 2018/6/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int count = 0;
    for (int i = 0; i < (int)grid.size(); i++) {
        for (int j = 0; j < (int)grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            int tmp = 0;
            tmp += (i == 0 || grid[i-1][j] == 0) ? 1 : 0; // up
            tmp += (j == 0 || grid[i][j-1] == 0) ? 1 : 0; // left
            tmp += (i == (int)grid.size() - 1 || grid[i+1][j] == 0) ? 1 : 0; // down
            tmp += (j == (int)grid[0].size() - 1 || grid[i][j+1] == 0) ? 1 : 0; //right
            count += tmp;
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> grid{vector<int>{0,1,0,0}, vector<int>{1,1,1,0}, vector<int>{0,1,0,0}, vector<int>{1,1,0,0}};
    cout<<islandPerimeter(grid)<<endl;
    return 0;
}
