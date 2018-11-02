//
//  main.cpp
//  771. Jewels and Stones
//
//  Created by Jie Lu on 2018/6/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int numJewelsInStones(string J, string S) {
    int jewels[128] = {0};
    for (auto c : J) {
        jewels[c] += 1;
    }
    int count = 0;
    for (auto c : S) {
        if (jewels[c] > 0) {
            count++;
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    cout<<numJewelsInStones("aA", "afalkfjA")<<endl;
    return 0;
}
