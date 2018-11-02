//
//  main.cpp
//  241. Different Ways to Add Parentheses
//
//  Created by Jie Lu on 2018/5/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] < '0') {
            vector<int> v1 = diffWaysToCompute(input.substr(0, i));
            vector<int> v2 = diffWaysToCompute(input.substr(i + 1));
            for (auto i1 : v1)
            {
                for (auto i2 : v2)
                {
                    switch (input[i]) {
                        case '+':
                            res.push_back(i1 + i2);
                            break;
                        case '-':
                            res.push_back(i1 - i2);
                            break;
                        case '*':
                            res.push_back(i1 * i2);
                    }
                }
            }
        }
    }
    if (res.empty())
        res.push_back(stoi(input));
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> res = diffWaysToCompute("2-1-1");
    for (auto num : res) {
        cout<<num<<endl;
    }
    return 0;
}
