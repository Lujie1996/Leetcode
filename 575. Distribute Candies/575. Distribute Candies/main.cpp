//
//  main.cpp
//  575. Distribute Candies
//
//  Created by Jie Lu on 2018/7/18.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int distributeCandies(vector<int>& candies) {
    unordered_map<int, int> candyCount;
    for (auto candy : candies) {
        candyCount[candy] += 1;
    }
    if (candyCount.size() <= candies.size() / 2) {
        return (int)candyCount.size();
    }
    return (int)candies.size() / 2;
}
int main(int argc, const char * argv[]) {
    vector<int> candies{1,1,2,3,4,5};
    cout<<distributeCandies(candies)<<endl;
    return 0;
}
