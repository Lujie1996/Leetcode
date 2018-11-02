//
//  main.cpp
//  346. Moving Average from Data Stream
//
//  Created by Jie Lu on 2018/6/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MovingAverage {
private:
    int index, size, sum, cnt;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        nums.resize(size, 0);
        this->size = size;
        index = 0;
        sum = 0;
        cnt = 0;
    }
    
    double next(int val) {
        sum -= nums[(index+1)%size];
        sum += val;
        nums[(++index)%size] = val;
        if (cnt < size) {
            cnt++;
            return (double)sum / cnt;
        }
        return (double)sum / size;
    }
};
int main(int argc, const char * argv[]) {
    MovingAverage* m = new MovingAverage(3);
    cout<<m->next(1)<<endl;
    cout<<m->next(8)<<endl;
    cout<<m->next(3)<<endl;
    cout<<m->next(4)<<endl;
    return 0;
}
