//
//  main.cpp
//  557. Reverse Words in a String III
//
//  Created by Jie Lu on 2018/5/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

string reverseWords(string s) {
    int low = 0, high = 0, n = (int)s.length(), nextLow = 0;
    while (low < n) {
        while (s[high] != ' ' && high < n) {
            high++;
        }
        nextLow = high + 1;
        high--;
        while (low < high) {
            char c = s[low];
            s[low] = s[high];
            s[high] = c;
            low++;
            high--;
        }
        low = nextLow;
        high = low;
    }
    return s;
}
int main(int argc, const char * argv[]) {
    cout<<reverseWords("Let's take LeetCode contest")<<endl;
    return 0;
}
