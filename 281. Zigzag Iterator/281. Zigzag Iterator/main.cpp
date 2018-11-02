//
//  main.cpp
//  281. Zigzag Iterator
//
//  Created by Jie Lu on 2018/6/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// This is my original solution. This can be easily modified to fit the follow-up which has more than 2 vectors.
class ZigzagIterator {
private:
    vector<vector<int>::iterator> iters, ends;
    int whichChosen = 0, n = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        n = 2;
        iters.push_back(v1.begin());
        iters.push_back(v2.begin());
        ends.push_back(v1.end());
        ends.push_back(v2.end());
    }
    
    int next() {
        return *iters[whichChosen++ % n]++;
    }
    
    bool hasNext() {
        int count = 0;
        while (iters[whichChosen % n] == ends[whichChosen % n] && count < n) {
            whichChosen++;
            count++;
        }
        return count != n;
        // if all vectors are traversed but still cannot find one which is not at its end
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a{1,2,3,4,5}, b{6,7,8};
    ZigzagIterator obj(a, b);
    while (obj.hasNext()) {
        cout<<obj.next()<<" ";
    }
    cout<<endl;
    return 0;
}
