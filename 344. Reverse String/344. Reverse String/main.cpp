//
//  main.cpp
//  344. Reverse String
//
//  Created by Jie Lu on 2018/5/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

string reverseString(string s) {
    int low = 0, high = (int)s.length() - 1;
    char c;
    while (low < high) {
        c = s[low];
        s[low] = s[high];
        s[high] = c;
        low++;
        high--;
    }
    return s;
}
int main(int argc, const char * argv[]) {
    cout<<reverseString("absdeg")<<endl;
    return 0;
}
