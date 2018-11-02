//
//  main.cpp
//  274. H-Index
//
//  Created by Jie Lu on 2018/5/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//int hIndex(vector<int>& citations) {
//    sort(citations.begin(), citations.end());
//    int count = 0;
//    for (int i = (int)citations.size() - 1; i >=0 ; i--) {
//        if (count >= citations[i]) {
//            break;
//        }
//        count += 1;
//    }
//    return count;
//}

// Same idea, but use binary search to accelorate.
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int left = 0, len = (int)citations.size(), right = len-1,  mid;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(citations[mid] >= (len-mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return len - left;
}
int main(int argc, const char * argv[]) {
    int a[] = {100};
    vector<int> nums(a, a+1);
    cout<<hIndex(nums)<<endl;
    return 0;
}
