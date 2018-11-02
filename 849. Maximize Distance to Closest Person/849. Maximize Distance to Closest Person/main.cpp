//
//  main.cpp
//  849. Maximize Distance to Closest Person
//
//  Created by Jie Lu on 2018/10/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxDistToClosest(vector<int>& seats) {
    int pre = 0, i = 0, maxDist = 0;
    // pre denotes the index of the staring 0
    while (i < seats.size()) {
        while (i < seats.size() && seats[i] == 0) {
            i++;
        }
        if (i != seats.size() && i != pre) {
            int dist = pre == 0 ? i : (i - pre + 1) / 2;
            maxDist = max(maxDist, dist);
        }
        else if (i == seats.size()) {
            maxDist = max(maxDist, i - pre);
            break;
        }
        while (i < seats.size() && seats[i] == 1) {
            i++;
        }
        pre = i;
    }
    return maxDist;
}

int main(int argc, const char * argv[]) {
    vector<int> seats{1,0,0,0};
    cout<<maxDistToClosest(seats)<<endl;
    return 0;
}
