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

int partition(vector<Interval>& intervals, int low, int high) {
    Interval pivot = intervals[low];
    while (low < high) {
        while (low < high && intervals[high].start >= pivot.start) {
            // it has to be >= instead of >. Using > results in infinite for loop when all nums[low to high] are the same
            high--;
        }
        intervals[low] = intervals[high];
        while (low < high && intervals[low].start <= pivot.start) {
            low++;
        }
        intervals[high] = intervals[low];
    }
    intervals[low] = pivot;
    return low;
}
void qsort(vector<Interval>& intervals, int low, int high) {
    if (low < high) {
        int pivot_index = partition(intervals, low, high);
        qsort(intervals, low, pivot_index - 1);
        qsort(intervals, pivot_index + 1, high);
    }
}
vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if (intervals.size() < 1) {
        return res;
    }
    qsort(intervals, 0, (int)intervals.size()-1);
    int start = intervals[0].start, end = intervals[0].end;
    for (int i=0; i<intervals.size(); i++) {
        if (end >= intervals[i].end) {
            continue;
        }
        else if (end >= intervals[i].start) {
            end = intervals[i].end;
        }
        else {
            res.push_back(Interval(start, end));
            start = intervals[i].start;
            end = intervals[i].end;
        }
    }
    res.push_back(Interval(start, end));
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
