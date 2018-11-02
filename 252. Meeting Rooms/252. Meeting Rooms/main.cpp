//
//  main.cpp
//  252. Meeting Rooms
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
bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){return a.start < b.start;});
    int end = -1;
    for (auto t : intervals) {
        if (t.start < end) {
            return false;
        }
        end = t.end;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    Interval a(2,4), b(4,7);
    vector<Interval> intervals{a,b};
    if (canAttendMeetings(intervals)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
