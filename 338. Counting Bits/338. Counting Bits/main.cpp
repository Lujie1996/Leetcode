//
//  main.cpp
//  338. Counting Bits
//
//  Created by Jie Lu on 2018/6/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// another solution from BBS. Actually this is not smarter in my opinion.
vector<int> countBits(int num) {
    vector<int> ret(num+1, 0);
    for (int i = 1; i <= num; ++i)
        ret[i] = ret[i&(i-1)] + 1;
    // i & (i - 1) clears the lowest set-bit of i
    return ret;
}
//vector<int> countBits(int num) {
//    vector<int> res;
//    for (int i = 0; i <= num; i++) {
//        int count = 0, t = i;
//        while (t) {
//            count += (t & 1);
//            t >>= 1;
//        }
//        res.push_back(count);
//    }
//    return res;
//}
int main(int argc, const char * argv[]) {
    vector<int> res = countBits(50);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
