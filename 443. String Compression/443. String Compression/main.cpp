//
//  main.cpp
//  443. String Compression
//
//  Created by Jie Lu on 2018/5/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int len = 0, count = 0, i = 0;
    char dup = chars[0];
    chars.push_back(0);
    for (char c : chars) {
        if (c == dup) {
            count++;
        }
        else {
            chars[i++] = dup;
            if (count == 1) {
                len++;
            }
            else {
                len++;
                vector<int> tmp;
                while (count) {
                    tmp.push_back(count % 10);
                    count /= 10;
                    len++;
                }
                for (int j = (int)tmp.size() - 1; j >= 0; j--) {
                    chars[i++] = tmp[j] + '0';
                }
            }
            dup = c;
            count = 1;
        }
    }
    return len;
}
void printVector(const vector<char>& chars, int len) {
    for (int i = 0; i < len; i++) {
        cout<<chars[i]<<" ";
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    vector<char> chars{'a','b','b','b'};
    printVector(chars, compress(chars));
    vector<char> chars2{'a','a','a','b','b','b'};
    printVector(chars2, compress(chars2));
    return 0;
}
