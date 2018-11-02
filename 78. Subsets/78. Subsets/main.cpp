//
//  main.cpp
//  78. Subsets
//
//  Created by Jie Lu on 2018/4/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void genSubsets(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int pos) {
    res.push_back(cur);
    for (int i = pos; i < nums.size(); i++) {
        cur.push_back(nums[i]);
        genSubsets(res, cur, nums, i + 1);
        cur.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    genSubsets(res, cur, nums, 0);
    return res;
}

//    This problem can also be solved iteratively. Take [1, 2, 3] in the problem statement as an example. The process of generating all the subsets is like:
//
//    Initially: [[]]
//    Adding the first number to all the existed subsets: [[], [1]];
//    Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
//    Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].

//vector<vector<int>> subsets(vector<int>& nums) {
//    vector<vector<int>> subs(1, vector<int>());
//    for (int i = 0; i < nums.size(); i++) {
//        int n = (int)subs.size();
//        for (int j = 0; j < n; j++) {
//            subs.push_back(subs[j]); // copy a new subs[j]
//            subs.back().push_back(nums[i]); // expand the just being created subs[j] with nums[i]
//        }
//    }
//    return subs;
//}
int main(int argc, const char * argv[]) {
    int a[] = {1,2,3};
    vector<int> nums(a, a + 3);
    vector<vector<int>> res = subsets(nums);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"number of result: "<<res.size()<<endl;
    return 0;
}
