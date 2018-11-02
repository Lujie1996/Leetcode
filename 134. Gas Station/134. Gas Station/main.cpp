//
//  main.cpp
//  134. Gas Station
//  这道题目很巧妙，和计算“循环数组最大子串和”相似又有所不同
//  其实只要保证了total >=0 返回sum >=0 的起始位置即可。
//
//  Created by Jie Lu on 13/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
    int sum = 0, total = 0, diff = 0, start = 0;
    for(int i = 0; i < gas.size(); i++){
        diff = gas[i] - cost[i];
        total += diff;
        sum += diff;
        if(sum < 0){
            sum = 0;
            start = i + 1;
        }
    }
    return total >= 0 ? start : -1;
}
int main(int argc, const char * argv[]) {
    int a[] = {5,2,3,4};
    int b[] = {3,1,7,3};
    vector<int> gas(a,a+4);
    vector<int> cost(b,b+4);
    cout<<canCompleteCircuit(gas, cost)<<endl;
    return 0;
}
