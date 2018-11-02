//
//  main.cpp
//  374. Guess Number Higher or Lower
//
//  Created by Jie Lu on 2018/6/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>

using namespace std;

int target = 1702766719;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
    if (num > target) {
        return -1;
    }
    if (num < target) {
        return 1;
    }
    else {
        return 0;
    }
}
int guessNumber(int n) {
    int low = 1, high = n, mid = 0;
    while (true) {
        mid = low + (high - low) / 2;
        switch (guess(mid)) {
            case 0:
                return mid;
                break;
            case -1:
                high = mid - 1;
                break;
            case 1:
                low = mid + 1;
                break;
        }
    }
    return n;
}

int main(int argc, const char * argv[]) {
    cout<<guessNumber(2126753390)<<endl;
    return 0;
}
