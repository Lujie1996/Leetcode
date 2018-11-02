//
//  main.cpp
//  57. Insert Interval
//
//  Created by Jie Lu on 2018/9/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    int i = 0;
    vector<Interval> res;
    while (i < intervals.size() && intervals[i].start < newInterval.start) {
        res.push_back(intervals[i]);
        i++;
    }
    // intervals[i].start >= newInterval.start
    if (i > 0 && intervals[i-1].end >= newInterval.start) {
        newInterval.start = intervals[i-1].start;
        res.pop_back();
    }
    while (i < intervals.size() && intervals[i].start <= newInterval.end) {
        i++;
    }
    if (i > 0) {
        newInterval.end = max(intervals[i-1].end, newInterval.end);
    }
    res.push_back(newInterval);
    while (i < intervals.size()) {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<Interval> intervals{Interval(1,2),Interval(3,5),Interval(6,7),Interval(8,10),Interval(12,16)};
    Interval newInterval(4,8);
    
    vector<Interval> res = insert(intervals, newInterval);
    for (auto a : res) {
        cout<<a.start<<" "<<a.end<<endl;
    }
    return 0;
}
