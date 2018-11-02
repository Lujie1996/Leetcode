//
//  main.cpp
//  79. Word Search
//
//  Created by Jie Lu on 2018/4/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point {
    int row;
    int col;
    Point(int a, int b) : row(a), col(b) {};
    bool operator < (const Point& a) const {
        return row < a.row || (row == a.row && col < a.col);
    }
};
bool tryPath(vector<vector<char>>& board, set<Point> history, string word, Point prePoint) {
    if (word.length() == 0) {
        return true;
    }
    vector<Point> candidates;
    int preRow = prePoint.row, preCol = prePoint.col;
    string nextWord = word.substr(1,word.length());
    
    if (preRow - 1 >= 0) {
        candidates.push_back(Point(preRow - 1, preCol));
    }
    if (preRow + 1 < board.size()) {
        candidates.push_back(Point(preRow + 1, preCol));
    }
    if (preCol - 1 >= 0) {
        candidates.push_back(Point(preRow, preCol - 1));
    }
    if (preCol + 1 < board[0].size()) {
        candidates.push_back(Point(preRow, preCol + 1));
    }
    
    for (int i = 0; i < candidates.size(); i++) {
        Point thisCan = candidates[i];
        if (board[thisCan.row][thisCan.col] == word[0] && history.find(thisCan) == history.end()) {
            history.insert(thisCan);
            if (tryPath(board, history, nextWord, thisCan)) {
                return true;
            }
            set<Point>::iterator it = history.find(thisCan);
            history.erase(it);
        }
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    int i, j;
    set<Point> history;
    // 也可是直接对board进行修改，对于访问过的点把它改成‘*’即可。
    // 我的方法涉及对象Point的创建和set的频繁插入、删除和访问，在运行速度上逊色一些
    string nextWord = word.substr(1, word.length());
    for (i = 0; i < board.size(); i++) {
        for (j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                Point thisPoint = Point(i, j);
                history.insert(thisPoint);
                if(tryPath(board, history, nextWord, thisPoint)) {
                    return true;
                }
                set<Point>::iterator it = history.find(thisPoint);
                history.erase(it);
            }
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    vector<vector<char>> board;
    char a[] = {'a','b','c','e'}, b[] = {'s','f','c','s'}, c[] = {'a','d','e','e'};
    vector<char> chars1(a,a+4);
    vector<char> chars2(b,b+4);
    vector<char> chars3(c,c+4);
    board.push_back(chars1);
    board.push_back(chars2);
    board.push_back(chars3);
//    char a[] = {'a','a'};
//    vector<char> chars1(a,a+4);
//    board.push_back(chars1);
    if (exist(board,"abcced")) {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}
