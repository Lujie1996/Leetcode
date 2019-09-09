//
//  main.cpp
//  986. Interval List Intersections
//
//  Created by Jie Lu on 2019/2/9.
//  Copyright © 2019 Jie Lu. All rights reserved.
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

vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
    int i = 0, j = 0;
    vector<Interval> res;
    while (i < A.size() && j < B.size()) {
        while (j < B.size() && B[j].end < A[i].start) {
            j++;
        }
        if (j == B.size()) {
            break;
        }
        while (j < B.size() && B[j].start <= A[i].end) {
            res.push_back(Interval(max(A[i].start, B[j].start), min(A[i].end, B[j].end)));
            if (i + 1 < A.size() && B[j].end >= A[i+1].start) {
                break;
            }
            j++;
        }
        i++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<Interval> A{Interval(0,2),Interval(5,10),Interval(13,23),Interval(24,25)};
    vector<Interval> B{Interval(1,5),Interval(8,12),Interval(15,24),Interval(25,26)};
    vector<Interval> res = intervalIntersection(A, B);
    for (auto a : res) {
        cout<<a.start<<" "<<a.end<<endl;
    }
    return 0;
}
