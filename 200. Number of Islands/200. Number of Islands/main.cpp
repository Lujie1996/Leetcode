//
//  main.cpp
//  200. Number of Islands
//
//  Created by Jie Lu on 2018/6/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// DFS solution:
//void DFS(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
//    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
//        return;
//    }
//    if (grid[i][j] != '1' || visited[i][j]) {
//        return;
//    }
//    visited[i][j] = true;
//    DFS(grid, visited, i + 1, j);
//    DFS(grid, visited, i - 1, j);
//    DFS(grid, visited, i, j + 1);
//    DFS(grid, visited, i, j - 1);
//}
//int numIslands(vector<vector<char>>& grid) {
//    if (grid.size() == 0 || grid[0].size() == 0) {
//        return 0;
//    }
//    int m = (int)grid.size(), n = (int)grid[0].size(), res = 0;
//    vector<vector<bool>> visited(m, vector<bool>(n, false));
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (grid[i][j] == '1' && !visited[i][j]) {
//                DFS(grid, visited, i, j);
//                res++;
//            }
//        }
//    }
//    return res;
//}

// Union-Find solution:
// 1. Assign the number of islands with the number of '1's in grid;
// 2. Union islands. The order is from upper-left to lower-right. In the meantime reduce the number of islands;
// 3. Finally each island has a root which is the upper-left point of its connected subgragh.
vector<int> UN;
int cnt = 0;
int find(int p) {
    while (p != UN[p]){
        UN[p] = UN[UN[p]];
        p = UN[p];
    }
    return p;
}
void unionset(int m,int n){
    int rootM = find(m);
    int rootN = find(n);
    if (rootM == rootN)
        return;
    UN[rootN] = rootM;
    cnt--;
}
int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0)
        return 0;
    int length = (int)grid.size() * (int)grid[0].size();
    int width = (int)grid[0].size();
    UN = vector<int>(length, 0);
    for (int i = 0; i < length; i++){
        int x = i / width, y = i % width;
        if (grid[x][y] == '1')
            cnt++;
        UN[i] = i;
    }
    for (int j = 0; j < length; j++){
        int x = j / width, y = j % width;
        int down = x + 1, right = y+1;
        if (down < grid.size() && grid[x][y] == '1' && grid[down][y] == '1')
            unionset(j, j+width);
        if(right < grid[0].size() && grid[x][y] == '1' && grid[x][right] == '1')
            unionset(j, j+1);
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    vector<char> a{'1','1','0','0','0'}, b{'1','1','0','0','0'}, c{'0','0','1','0','0'}, d{'0','0','0','1','1'};
    vector<vector<char>> grid{a,b,c,d};
    cout<<numIslands(grid)<<endl;
    return 0;
}
