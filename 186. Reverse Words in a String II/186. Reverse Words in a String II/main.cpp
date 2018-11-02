//
//  main.cpp
//  186. Reverse Words in a String II
//
//  Created by Jie Lu on 2018/6/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void reverseWords(vector<char>& str) {
    reverse(str.begin(), str.end());
    int i = 0;
    while (i < str.size()) {
        int start = i;
        while (i < str.size() && str[i] != ' ') {
            i++;
        }
        reverse(str.begin() + start, str.begin() + i);
        while (i < str.size() && str[i] == ' ') {
            i++;
        }
    }
}
int main(int argc, const char * argv[]) {
    vector<char> str{'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    reverseWords(str);
    for (auto c : str) {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}
