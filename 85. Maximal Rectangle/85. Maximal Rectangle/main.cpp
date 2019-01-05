//
//  main.cpp
//  85. Maximal Rectangle
//
//  Created by Jie Lu on 2018/12/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void getIndexOfFirstLowerNum(const vector<int>& heights, vector<int>& res, int bias) {
    int n = heights.size();
    stack<pair<int, int>> st; // pair: {num, index}
    
    int init = bias == 1 ? 0 : n - 1;
    for (int i = init; i >= 0 && i < n; i += bias) {
        if (st.empty() || st.top().first <= heights[i]) {
            st.push({heights[i], i});
        }
        else {
            int cur = heights[i];
            while (!st.empty() && st.top().first > cur) {
                int index = st.top().second;
                st.pop();
                res[index] = i;
            }
            st.push({cur, i});
        }
    }
    while (!st.empty()) {
        int index = st.top().second;
        res[index] = -1;
        st.pop();
    }
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0), right(n, 0);
    getIndexOfFirstLowerNum(heights, left, -1);
    getIndexOfFirstLowerNum(heights, right, 1);
    
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int l = left[i];
        int r = right[i] == -1 ? n : right[i];
        maxArea = max(maxArea, heights[i]*(r-l-1));
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
    vector<int> heights(n, 0);
    for (int i = 0; i < m; i++) {
        vector<int> tmp(n, 0);
        for (int j = 0; j < n; j++) {
            tmp[j] = (matrix[i][j] == '1' ? heights[j] + 1 : 0);
        }
        heights = tmp;
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> matrix{
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}};
    cout<<maximalRectangle(matrix)<<endl;
    
    return 0;
}
