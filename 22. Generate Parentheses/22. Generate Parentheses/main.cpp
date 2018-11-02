//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by Jie Lu on 21/03/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getParanthesis(vector<string>& ans, string curr, int left, int right) {
    //left: number of remaining '('
    //right: number of remaining ')'
    if (left > right) {
        return;
    }
    if (left == 0 && right == 0) {
        ans.push_back(curr);
    }
    else {
        if (left > 0) {
            getParanthesis(ans, curr + "(", left - 1, right);
        }
        if(right > 0) {
            getParanthesis(ans, curr + ")", left, right -1);
        }
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    getParanthesis(ans, "", n, n);
    return ans;
}
int main(int argc, const char * argv[]) {
    vector<string> ans = generateParenthesis(3);
    for(int i = 0;i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
