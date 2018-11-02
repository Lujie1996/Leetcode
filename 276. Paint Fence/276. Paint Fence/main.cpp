//
//  main.cpp
//  276. Paint Fence
//
//  Created by Jie Lu on 2018/6/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int numWays(int n, int k) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return k;
    }
    int sameColor = k, diffColor = k * (k - 1);
    // sameColor: Number of possible painting ways with last two fences painted in same color;
    // diffColor: Number of possible painting ways with last two fences painted in different color.
    for (int i = 2; i < n; i++) {
        int tmp = diffColor;
        diffColor = (diffColor + sameColor) * (k - 1);
        sameColor = tmp;
        // If current and previous fence have same color, this could only come from last diffColor.
        // If it is from last sameColor, then there will be three consecutive fences having the same color.
    }
    return diffColor + sameColor;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
