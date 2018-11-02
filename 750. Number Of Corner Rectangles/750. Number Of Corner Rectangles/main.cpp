//
//  main.cpp
//  750. Number Of Corner Rectangles
//
//  Created by Jie Lu on 2018/9/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int countCornerRectangles(vector<vector<int>>& grid) {
    int res = 0;
    vector<vector<int>> count(grid.size(), vector<int>(grid[0].size(), 0));
    for (int row = 0; row < grid.size(); row++) {
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[row][i] == 1) {
                for (int j = i + 1; j < grid[0].size(); j++) {
                    if (grid[row][j] == 1) {
                        res += count[i][j];
                        count[i][j]++;
                    }
                }
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> grid{{1,1,1},{1,1,1},{1,1,1}};
    cout<<countCornerRectangles(grid)<<endl;
    return 0;
}
