//
//  main.cpp
//  84. Largest Rectangle in Histogram
//
//  Created by Jie Lu on 2018/7/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 1. Use a for loop, for every i, let height[i] be the lowest height and obtain an area.
    How to calculate the area? find the next lower height from both left and right side of i.
    e.g. heights = [2,1,5,6,2,3], when i is 2, heights[2] = 5, so heights[1] = 1 is the next lower height on left side, heights[4] = 2 is the next lower height on right side.
    The width will be (4-1) - (1+1) + 1 = 2, which is heights[5 and 6], the area is 2 * heights[2] = 10.
 2. It's OK to use two for loops to find the firstLowerLeft and firstLowerRight heights, but doing that takes lots of time.
    Use the trick in problem LC503. Next Greater Element II, that is to use stack to get the results.
 */
int largestRectangleArea(vector<int>& heights) {
    int n = (int)heights.size();
    vector<int> firstLowerLeft(n, 0), firstLowerRight(n, 0);
    stack<pair<int, int>> st;
    // get firstLowerRight
    for (int i = 0; i < n; i++) {
        int h = heights[i];
        while (!st.empty() && st.top().first > h) {
            firstLowerRight[st.top().second] = i;
            st.pop();
        }
        st.push(make_pair(h, i));
    }
    while (!st.empty()) {
        firstLowerRight[st.top().second] = -1;
        st.pop();
    }
    // get firstLowerLeft
    for (int i = n - 1; i >= 0; i--) {
        int h = heights[i];
        while (!st.empty() && st.top().first > h) {
            firstLowerLeft[st.top().second] = i;
            st.pop();
        }
        st.push(make_pair(h, i));
    }
    while (!st.empty()) {
        firstLowerLeft[st.top().second] = -1;
        st.pop();
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int left = firstLowerLeft[i] == -1 ? 0 : firstLowerLeft[i] + 1;
        int right = firstLowerRight[i] == -1 ? n - 1 : firstLowerRight[i] - 1;
        res = max(res, (right - left + 1) * heights[i]);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> heights{2,1,5,6,2,3};
    cout<<largestRectangleArea(heights)<<endl;
    return 0;
}
