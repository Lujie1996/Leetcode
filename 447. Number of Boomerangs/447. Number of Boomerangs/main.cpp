//
//  main.cpp
//  447. Number of Boomerangs
//
//  Created by Jie Lu on 2018/7/19.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 int res = 0;
 for (pointA : points)
    map pointCount;
    for (pointB : points exclude pointA)
        pointCount[dist(pointA, pointB)] += 1;
    for (t : pointCount)
        res += t.second >= 2 ? t.second * (t.second - 1) : 0;
 */
int numberOfBoomerangs(vector<pair<int, int>>& points) {
    if (points.size() < 3) {
        return 0;
    }
    int res = 0;
    for (int i = 0; i < points.size(); i++) {
        unordered_map<int, int> pointCount;
        // key: distance between points[j] and points[i]
        // value: number of such points[j]
        int x = points[i].first, y = points[i].second;
        for (int j = 0; j < points.size(); j++) {
            if (j == i) {
                continue;
            }
            int a = points[j].first - x, b = points[j].second - y, dist = a * a + b * b;
            pointCount[dist] += 1;
        }
        for (auto t : pointCount) {
            res += t.second >= 2 ? t.second * (t.second - 1) : 0;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<pair<int, int>> points{make_pair(0, 0), make_pair(1, 0), make_pair(2, 0)};
    // [[1,0],[2,0],[0,0]], [[1,0],[0,0],[2,0]], [[1,1],[0,0],[2,0]]
    cout<<numberOfBoomerangs(points)<<endl;
    return 0;
}
