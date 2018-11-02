//
//  main.cpp
//  593. Valid Square
//
//  Created by Jie Lu on 2018/9/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    vector<vector<int>> points{p1,p2,p3,p4};
    sort(points.begin(), points.end(), [] (vector<int>& a, vector<int>& b) {return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);});
    return (points[1][0] - points[0][0]) * (points[2][0] - points[0][0]) + (points[1][1] - points[0][1]) * (points[2][1] - points[0][1]) == 0 &&
    (points[1][0] - points[3][0]) * (points[2][0] - points[3][0]) + (points[1][1] - points[3][1]) * (points[2][1] - points[3][1]) == 0 &&
    (points[3][0] - points[0][0]) * (points[1][0] - points[2][0]) + (points[3][1] - points[0][1]) * (points[1][1] - points[2][1]) == 0 &&
    points[0][0] != points[2][1];
    // 左下顶角的两边垂直
    // 右上顶角的两边垂直
    // 对角线垂直
    // 防止四个点重叠
}

int main(int argc, const char * argv[]) {
    vector<int> p1{0,0}, p2{1,1}, p3{1,0}, p4{0,1};
    cout<<validSquare(p1, p2, p3, p4)<<endl;
    return 0;
}
