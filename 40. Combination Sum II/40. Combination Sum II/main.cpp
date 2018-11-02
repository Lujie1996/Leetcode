//
//  main.cpp
//  40. Combination Sum II
//
//  Created by Jie Lu on 21/03/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void getCombination(vector<int>& candidates, vector<vector<int>>& ans, vector<int> curr, int start, int target) {
    if (target == 0) {
        ans.push_back(curr);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if(candidates[i] > target) {
            return;
        }
        curr.push_back(candidates[i]);
        getCombination(candidates, ans, curr, i + 1, target - candidates[i]);
        curr.pop_back();
        while (i + 1 < candidates.size() && candidates[i + 1] == candidates[i]) {
            i++;
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    getCombination(candidates, ans, curr, 0, target);
    return ans;
}
int main(int argc, const char * argv[]) {
    int nums[] = {10,1,2,7,6,1,1,5};
    vector<int> candidates(nums, nums + 8);
    vector<vector<int>> ans = combinationSum2(candidates, 8);
    for(int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
