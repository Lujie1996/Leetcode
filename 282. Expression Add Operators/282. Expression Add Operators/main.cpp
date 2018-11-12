//
//  main.cpp
//  282. Expression Add Operators
//
//  Created by Jie Lu on 2018/11/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<string>& res, string curStr, string num, int pos, long curRes, int target, char preOp, long preNum) {
    if (pos == num.size() && curRes == target) {
        res.push_back(curStr.substr(1));
        return;
    }
    
    for (int i = pos; i < num.size(); i++) {
        string sub = num.substr(pos, i-pos+1);
        long thisNum = stol(sub);
        
        if (i - pos > 0 && (thisNum == 0 || thisNum < 10)) {
            // avoid "00" and "01"
            break;
        }
        
         // +
        dfs(res, curStr + "+" + sub, num, i + 1, curRes + thisNum, target,  '+', thisNum);
        if (pos == 0) {
            continue;
        }
        
        // -
        dfs(res, curStr + "-" + sub, num, i + 1, curRes - thisNum, target, '-', thisNum);
        
        // *
        if (preOp == '+') {
            dfs(res, curStr + "*" + sub, num, i + 1, curRes - preNum + preNum * thisNum, target, preOp, thisNum * preNum);
        }
        else if (preOp == '-') {
            dfs(res, curStr + "*" + sub, num, i + 1, curRes + preNum - preNum * thisNum, target, preOp, thisNum * preNum);
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(res, "", num, 0, 0, target, '+', 0);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<string> res = addOperators("000", 0);
    for (auto s : res) {
        cout<<s<<endl;
    }
    return 0;
}
