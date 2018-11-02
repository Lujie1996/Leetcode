//
//  main.cpp
//  803. Bricks Falling When Hit
//
//  Created by Jie Lu on 2018/10/19.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <ctime>
using namespace std;

// solution 1. TLE in 11/16 test case
struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first + v.second;
    }
};
//
//void dfs(vector<vector<int>>& grid, unordered_set<pair<int, int>, pair_hash>& connected, int i, int j) {
//    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || connected.find({i,j}) != connected.end()) {
//        return;
//    }
//    connected.insert({i,j});
//    dfs(grid, connected, i-1, j);
//    dfs(grid, connected, i+1, j);
//    dfs(grid, connected, i, j-1);
//    dfs(grid, connected, i, j+1);
//}
//
//int countFrom(vector<vector<int>>& grid, int i, int j) {
//    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
//        return 0;
//    }
//    unordered_set<pair<int, int>, pair_hash> connected;
//    dfs(grid, connected, i, j);
//
//    bool willDrop = true;
//    for (auto brick : connected) {
//        if (brick.first == 0) {
//            willDrop = false;
//        }
//    }
//    if (willDrop) {
//        for (auto brick : connected) {
//            grid[brick.first][brick.second] = 0;
//        }
//    }
//
//    return willDrop ? (int)connected.size() : 0;
//}
//
//// return after hit [i,j] how many bricks connected to [i,j] will drop
//int hitBrick(vector<vector<int>>& grid, int i, int j) {
//    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 ) {
//        return 0;
//    }
//    grid[i][j] = 0;
//
//    int count = 0;
//    count += countFrom(grid, i-1, j);
//    count += countFrom(grid, i+1, j);
//    count += countFrom(grid, i, j-1);
//    count += countFrom(grid, i, j+1);
//    return count;
//}
//
//vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
//    vector<int> res;
//    for (auto hit : hits) {
//        if (hit[0] == 0 && hit[1] == 4) {
//
//        }
//        res.push_back(hitBrick(grid, hit[0], hit[1]));
//    }
//    return res;
//}


// solution 2. Starting form the top row, dfs to get all connected components linked with top row.
// Still TLE at test case 11/16
int noOfOnes(vector<vector<int>>& grid) {
    int count = 0;
    for (auto row : grid) {
        for (auto cell : row) {
            count += cell == 1 ? 1 : 0;
        }
    }
    return count;
}

// count no of ones, set one to zero, set -1 to 1
int countAndSet(vector<vector<int>>& grid) {
    int count = 0;
    for (auto& row : grid) {
        for (auto& cell : row) {
            if (cell == 1) {
                count++;
                cell = 0;
            }
            else if (cell == -1) {
                cell = 1;
            }
        }
    }
    return count;
}

void dfs_mark(vector<vector<int>>& grid, unordered_set<pair<int, int>, pair_hash>& visited, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1 || grid[i][j] == 0 || visited.find({i,j}) != visited.end()) {
        return;
    }
    grid[i][j] = -1;
    visited.insert({i,j});
    dfs_mark(grid, visited, i-1, j);
    dfs_mark(grid, visited, i+1, j);
    dfs_mark(grid, visited, i, j-1);
    dfs_mark(grid, visited, i, j+1);
}

int hitBrick(vector<vector<int>>& grid, int i, int j, int& no) {
    grid[i][j] = 0;
    for (int k = 0; k < grid[0].size(); k++) {
        unordered_set<pair<int, int>, pair_hash> visited;
        if (grid[0][k] == 1) {
            dfs_mark(grid, visited, 0, k);
        }
    }
    int ones = countAndSet(grid);
    no -= ones;
    return ones;
}

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    vector<int> res;
    int ones = noOfOnes(grid);
    for (auto hit : hits) {
        res.push_back(hitBrick(grid, hit[0], hit[1], ones));
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid{{0,1,1,1,1,1},{1,1,1,1,1,1,},{0,0,1,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    vector<vector<int>> hits{{1,3},{3,5},{0,3},{3,3},{1,1},{4,2},{1,0},{3,0},{4,5},{2,1},{4,4},{4,0},{2,4},{2,5},{3,4},{0,5},{0,4},{3,2},{1,5},{4,1},{2,2},{0,2}};
    clock_t start = clock();
    vector<int> res = hitBricks(grid, hits);
    double duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout<<duration<<endl;
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
