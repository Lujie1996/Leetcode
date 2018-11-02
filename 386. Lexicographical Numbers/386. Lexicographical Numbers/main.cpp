//
//  main.cpp
//  386. Lexicographical Numbers
//
//  Created by Jie Lu on 2018/7/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// This is my original solution. TLE when n is very big. (Since n could be up to 5,000,000)
//vector<int> lexicalOrder(int n) {
//    vector<int> res(n, 0);
//    for (int i = 1; i <= n; i++) {
//        res[i-1] = i;
//    }
//    sort(res.begin(), res.end(), [](const int& a, const int& b) -> bool {
//        return to_string(a) < to_string(b);
//    });
//    return res;
//}

// From BBS. 
vector<int> lexicalOrder(int n) {
    vector<int> res(n);
    int cur = 1;
    for (int i = 0; i < n; i++) {
        res[i] = cur;
        if (cur * 10 <= n) {
            cur *= 10;
        }
        else {
            if (cur >= n)
                cur /= 10;
            cur += 1;
            while (cur % 10 == 0)
                cur /= 10;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> res = lexicalOrder(50000);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
