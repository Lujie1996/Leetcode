//
//  main.cpp
//  253. Meeting Rooms II
//
//  Created by Jie Lu on 2018/6/10.
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
// 1, sort intervals according to start time;
// 2, Traverse the intervals for several times. Each time gets a sequence of intervals which are not not-overlapping;
// 3, The number of sequences is the number of needed rooms.
// Note that once an interval is visited, it will not be visited on all later traverses.
int minMeetingRooms(vector<Interval>& intervals) {
    int n = (int)intervals.size(), count = 0, res = 0;
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){return a.start < b.start;});
    vector<bool> visited(n, false);
    while (count < n) {
        int end = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (intervals[i].start >= end) {
                    end = intervals[i].end;
                    count++;
                    visited[i] = true;
                }
            }
        }
        res++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // [0, 30],[5, 10],[15, 20]
    Interval a(0,30), b(5,10), c(15,20);
    vector<Interval> intervals{a,b,c};
    cout<<minMeetingRooms(intervals)<<endl;
    return 0;
}
