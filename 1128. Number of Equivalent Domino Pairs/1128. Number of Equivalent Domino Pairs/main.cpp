//
//  main.cpp
//  1128. Number of Equivalent Domino Pairs
//
//  Created by Jie Lu on 2019/8/14.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<pair<int,int>,int> freq;
    int ans = 0;
    for(auto dn : dominoes){
        if(dn[0] > dn[1])
            swap(dn[0], dn[1]);
        ans += freq[{dn[0], dn[1]}] ++;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> dominoes{{1,2},{2,1},{3,4},{5,6}};
    cout<<numEquivDominoPairs(dominoes)<<endl;
    return 0;
}
