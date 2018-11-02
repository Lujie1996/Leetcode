//
//  main.cpp
//  542. 01 Matrix
//
//  Created by Jie Lu on 2018/8/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& matrix, int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    q.push(make_pair(-1, -1));
    int count = 0;
    while (true) {
        while (q.front().first != -1) {
            if (matrix[q.front().first][q.front().second] == 0) {
                return count;
            }
            else {
                i = q.front().first;
                j = q.front().second;
                if (i - 1 >= 0) {
                    q.push(make_pair(i-1, j));
                }
                if (i + 1 < matrix.size()) {
                    q.push(make_pair(i+1, j));
                }
                if (j - 1 >= 0) {
                    q.push(make_pair(i, j-1));
                }
                if (j + 1 < matrix[0].size()) {
                    q.push(make_pair(i, j+1));
                }
            }
            q.pop();
        }
        q.pop();
        q.push(make_pair(-1, -1));
        count++;
    }
    return count;
}
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
        return matrix;
    }
    int m = (int)matrix.size(), n = (int)matrix[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = bfs(matrix, i ,j);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix{{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> res = updateMatrix(matrix);
    for (auto row : res) {
        for (auto num : row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
