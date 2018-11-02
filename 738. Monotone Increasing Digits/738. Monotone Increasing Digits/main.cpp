//
//  main.cpp
//  738. Monotone Increasing Digits
//
//  Created by Jie Lu on 2018/7/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int monotoneIncreasingDigits(int N) {
    vector<int> digits;
    int t = N;
    while (t) {
        digits.push_back(t % 10);
        t /= 10;
    }
    reverse(digits.begin(), digits.end());
    for (int i =  0; i < (int)digits.size(); i++) {
        if (digits[i] >= digits[i-1]) {
            continue;
        }
        else {
            digits[i] = 9;
            digits[i-1] = (9 + digits[i-1]) % 10; // minus 1 (corner case: 0 to 9 not -1)
            for (int j = i - 1; j > 0; j--) {
                if (digits[j] < digits[j-1]) {
                    digits[j] = 9;
                    digits[j-1] = (9 + digits[j-1]) % 10;
                }
                else {
                    break;
                }
            }
            while (i < (int)digits.size()) {
                digits[i] = 9;
                i++;
            }
        }
    }
    int res = 0, base = 1;
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
        res += base * digits[i];
        base *= 10;
    }
    return res;
}

// From Discuss. for loop from rear to from, amd is much more concise
//int monotoneIncreasingDigits(int N) {
//    string n_str = to_string(N);
//    int loc = (int)n_str.size(), res = 0;
//    for (int i = (int)n_str.size() - 1; i > 0; i--)
//        if (n_str[i] < n_str[i - 1]) {
//            loc = i;
//            n_str[i - 1] -= 1;
//        }
//    for (int i = loc; i < n_str.size(); i++)
//        n_str[i] = '9';
//    return stoi(n_str);
//}

int main(int argc, const char * argv[]) {
    cout<<monotoneIncreasingDigits(100)<<endl;
    cout<<monotoneIncreasingDigits(123)<<endl;
    cout<<monotoneIncreasingDigits(332)<<endl;
    return 0;
}
