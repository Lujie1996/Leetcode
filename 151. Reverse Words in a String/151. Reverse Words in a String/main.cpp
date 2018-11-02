//
//  main.cpp
//  151. Reverse Words in a String
//
//  Created by Jie Lu on 2018/4/24.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;
int format(string& s) {
    int n = (int)s.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ' || (i > 0 && s[i-1] != ' ')) {
            s[count++] = s[i];
        }
    }
    // handle the case where after last word, all were spaces
    if (s[count-1] == ' ') count--;
    s.resize(count);
    return count;
}
void reverseWords(string &s) {
    if (format(s) == 0) {
        //input string may contain spaces in the beginning and ending parts, format() erases those spaces and return remaining length
        return;
    }
    int n = (int)s.length(), l = 0, r = 0;
    int indexOfSpace = 0;
    reverse(s.begin(), s.end());
    while (indexOfSpace != n) {
        while (r < n && s[r] != ' ') {
            r++;
        }
        indexOfSpace = r;
        r--;
        reverse(s.begin()+l, s.begin()+r+1);
        l = r = indexOfSpace + 1;
    }
}
int main(int argc, const char * argv[]) {
    string s = "   a  b  ";
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}
