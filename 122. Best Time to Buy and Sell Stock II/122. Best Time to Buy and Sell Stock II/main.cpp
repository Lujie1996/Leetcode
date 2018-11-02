//
//  main.cpp
//  122. Best Time to Buy and Sell Stock II
//
//  Created by Jie Lu on 2018/4/24.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    cout<<prices.size()<<endl;
    int total = 0;
    for (int i=0; i<(int)prices.size()-1; i++) {
        if (prices[i+1]>prices[i])
            total += prices[i+1]-prices[i];
    }
    return total;
}
int main(int argc, const char * argv[]) {
    int a[] = {7,1,5,3,6,4};
    vector<int> nums(a,a);
    cout<<maxProfit(nums)<<endl;
    return 0;
}
