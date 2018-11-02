//
//  main.cpp
//  553. Optimal Division
//
//  Created by Jie Lu on 2018/5/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string optimalDivision(vector<int>& nums) {
    /*
     Here is why "a/(b/c/d)" is optimal.
         To prove: b/c/d < b/(c/d),
         that is to prove: b/cd < bd/c,
         that is to prove: b/cd < bdd/cd,
         that is to prove: 1 < d*d.
         Since Elements in the given array will be in range [2, 1000],
         thus d*d > 1 holds.
         In a case where nums.size() is greater, it could always be iteratively converted to this problem.
     End
     */
    
    string ans;
    if(!nums.size())
        return ans;
    ans = to_string(nums[0]);
    if(nums.size()==1)
        return ans;
    if(nums.size()==2)
        return ans + "/" + to_string(nums[1]);
    ans += "/(" + to_string(nums[1]);
    for(int i = 2; i < nums.size();++i)
        ans += "/" + to_string(nums[i]);
    ans += ")";
    return ans;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1000,100,10,2};
    cout<<optimalDivision(nums)<<endl;
    return 0;
}
