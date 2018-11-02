//
//  main.cpp
//  179. Largest Number
//
//  Created by Jie Lu on 2018/4/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string largestNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end(),
         [](const int &m,const int&n){
             return to_string(m) + to_string(n) > to_string(n) + to_string(m);});
    string res;
    for (int i = 0; i < (int)nums.size(); i++) {
        res += to_string(nums[i]);
    }
    if(res[0]=='0') //for the case nums are all zeros
        return "0";
    return res;
}
int main(int argc, const char * argv[]) {
    int a[] = {37,30,34,5,9};
    vector<int> nums(a, a+5);
    cout<<largestNumber(nums)<<endl;
    return 0;
}
