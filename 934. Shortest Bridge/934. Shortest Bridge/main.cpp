//
//  main.cpp
//  934. Shortest Bridge
//
//  Created by Jie Lu on 2018/11/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(queue<pair<int,int>>& q, const vector<vector<int>>& A, vector<vector<bool>>& visited, int row, int col) {
    if (row < 0 || row >= A.size() || col < 0 || col >= A[0].size() || A[row][col] == 0 || visited[row][col]) {
        return;
    }
    q.push({row, col});
    visited[row][col] = true;
    dfs(q, A, visited, row-1, col);
    dfs(q, A, visited, row+1, col);
    dfs(q, A, visited, row, col-1);
    dfs(q, A, visited, row, col+1);
}

void getAllInQ(queue<pair<int,int>>& q, const vector<vector<int>>& A, int row, int col) {
    q.push({row, col});
    vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
    dfs(q, A, visited, row, col);
}

pair<int,int> findOne(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == 1) {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int shortestBridge(vector<vector<int>>& A) {
    queue<pair<int,int>> q;
    int m = A.size(), n = A[0].size();
    
    pair<int, int> one = findOne(A);
    getAllInQ(q, A, one.first, one.second);
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    int res = 0;
    q.push({-1,-1});
    
    vector<vector<int>> nextSteps{{-1,0},{1,0},{0,-1},{0,1}};
    
    while (!q.empty()) {
        pair<int,int> front = q.front();
        q.pop();
        int row = front.first, col = front.second;
        if (row == -1) {
            res += 1;
            q.push({-1,-1});
            continue;
        }
        
        if (res == 0) {
            visited[row][col] = true;
        }
        for (auto next : nextSteps) {
            int nextRow = row + next[0];
            int nextCol = col + next[1];
            if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol]) {
                if (A[nextRow][nextCol] == 1 && res != 0) {
                    return res;
                }
                q.push({nextRow, nextCol});
                visited[nextRow][nextCol] = true;
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    vector<vector<int>> A{{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    vector<vector<int>> A{{0,1},{1,0}};
    cout<<shortestBridge(A)<<endl;
    return 0;
}
