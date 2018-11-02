//
//  main.cpp
//  130. Surrounded Regions
//
//  Created by Jie Lu on 2018/4/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
void bfsBoundary(vector<vector<char> >& board, int w, int l)
{
    int width = (int)board.size();
    int length = (int)board[0].size();
    deque<pair<int, int>> q;
    q.push_back(make_pair(w, l));
    board[w][l] = 'B';
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop_front();
        pair<int, int> adjs[4] = {
            {cur.first-1, cur.second},
            {cur.first+1, cur.second},
            {cur.first, cur.second-1},
            {cur.first, cur.second+1}
        };
        for (int i = 0; i < 4; ++i)
        {
            int adjW = adjs[i].first;
            int adjL = adjs[i].second;
            if ((adjW >= 0) && (adjW < width) && (adjL >= 0) && (adjL < length) && (board[adjW][adjL] == 'O')) {
                q.push_back(make_pair(adjW, adjL));
                board[adjW][adjL] = 'B';
            }
        }
    }
}

void solve(vector<vector<char> > &board) {
    // Use BFS starting from 'O’s on the boundary and mark them as ‘B’, then iterate over the whole board and mark ‘O’ as ‘X’ and ‘B’ as ‘O’.
    
    int width = (int)board.size();
    if (width == 0) //Add this to prevent run-time error!
        return;
    int length = (int)board[0].size();
    if  (length == 0) // Add this to prevent run-time error!
        return;
    
    for (int i = 0; i < length; ++i)
    {
        if (board[0][i] == 'O')
            bfsBoundary(board, 0, i);
        
        if (board[width-1][i] == 'O')
            bfsBoundary(board, width-1, i);
    }
    
    for (int i = 0; i < width; ++i)
    {
        if (board[i][0] == 'O')
            bfsBoundary(board, i, 0);
        if (board[i][length-1] == 'O')
            bfsBoundary(board, i, length-1);
    }
    
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'B')
                board[i][j] = 'O';
        }
    }
}
int main(int argc, const char * argv[]) {
    char row1[] = {'X','X','X','X'};
    char row2[] = {'X','O','O','X'};
    char row3[] = {'X','X','O','X'};
    char row4[] = {'X','O','X','X'};
    vector<vector<char>> board;
    board.push_back(vector<char>(row1, row1+4));
    board.push_back(vector<char>(row2, row2+4));
    board.push_back(vector<char>(row3, row3+4));
    board.push_back(vector<char>(row4, row4+4));
    solve(board);
    printBoard(board);
    return 0;
}
