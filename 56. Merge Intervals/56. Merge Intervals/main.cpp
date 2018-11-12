//
//  main.cpp
//  56. Merge Intervals
//
//  Created by Jie Lu on 2018/4/4.
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

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if (intervals.size() == 0) {
        return res;
    }
    
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){return a.start < b.start || a.start == b.start && a.end < b.end;});
    
    int preStart = intervals[0].start, preEnd = intervals[0].end;
    for (auto interval : intervals) {
        if (interval.start <= preEnd) {
            preEnd = max(preEnd, interval.end);
        }
        else {
            res.push_back(Interval(preStart, preEnd));
            preStart = interval.start;
            preEnd = interval.end;
        }
    }
    res.push_back(Interval(preStart, preEnd));
    return res;
}
int main(int argc, const char * argv[]) {
    vector<Interval> intervals;
    intervals.push_back(Interval(1,2));
    intervals.push_back(Interval(1,2));
    vector<Interval> res = merge(intervals);
    for (int i=0; i<res.size(); i++) {
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
    return 0;
}
