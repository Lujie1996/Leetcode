//
//  main.cpp
//  135. Candy
//
//  Created by Jie Lu on 2018/10/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// brute force. TLE. O(n^2) time and O(n) time
int candy(vector<int>& ratings) {
    vector<int> candies(ratings.size(), 1);
    bool flag = true;
    
    while (flag) {
        flag = false;
        for (int i = 0; i < ratings.size(); i++) {
            if (i - 1 >= 0 && ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]) {
                flag = true;
                candies[i] = candies[i-1] + 1;
            }
            if (i + 1 < ratings.size() && ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                flag = true;
                candies[i] = candies[i+1] + 1;
            }
        }
    }
    
    int sum = 0;
    for (auto candy : candies) {
        sum += candy;
    }
    return sum;
}

// O(n) time and O(n) space. Very smart and easy to understand.
int candy2(vector<int>& ratings) {
    vector<int> l2r(ratings.size(), 1), r2l(ratings.size(), 1);
    for (int i = 0; i < ratings.size(); i++) {
        if (i - 1 >= 0 && ratings[i] > ratings[i-1]) {
            l2r[i] = l2r[i-1] + 1;
        }
        else {
            l2r[i] = 1;
        }
    }
    
    for (int i = ratings.size() - 1; i >= 0; i--) {
        if (i + 1 < ratings.size() && ratings[i] > ratings[i+1]) {
            r2l[i] = r2l[i+1] + 1;
        }
        else {
            r2l[i] = 1;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < ratings.size(); i++) {
        sum += max(l2r[i], r2l[i]);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    vector<int> ratings{1,3,2,1};
    cout<<candy2(ratings)<<endl;
    return 0;
}
