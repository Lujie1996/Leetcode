//
//  main.cpp
//  93. Restore IP Addresses
//
//  Created by Jie Lu on 2018/4/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getIp(vector<string>& res, string cur, int no, string& s, int start) {
    if (no == 4 && start == s.length()) {
        cur.pop_back();
        res.push_back(cur);
        return;
    }
    int lowestStart = (int)s.length() - 3 * (3 - no);
    if (lowestStart - start > 3) {
        return;
    }
    int minLen = lowestStart > start ? (lowestStart - start) : 1;
    int maxLen = min(3, (int)s.length() - start - (3 - no));
    for (int i = minLen; i <= maxLen; i++) {
        string front = s.substr(start, i);
        if (front.length() > 1 && front[0] == '0') {
            return;
        }
        int a = stoi(front);
        if (a>= 0 && a<= 255) {
            front += ".";
            getIp(res, cur + front, no + 1, s, start + i);
        }
    }
}
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string cur = "";
    getIp(res, cur, 0, s, 0);
    return res;
}
// 别人的代码，非常直接的解决了这个问题
//vector<string> restoreIpAddresses(string s) {
//    vector<string> ret;
//    string ans;
//
//    for (int a=1; a<=3; a++)
//        for (int b=1; b<=3; b++)
//            for (int c=1; c<=3; c++)
//                for (int d=1; d<=3; d++)
//                    if (a+b+c+d == s.length()) {
//                        int A = stoi(s.substr(0, a));
//                        int B = stoi(s.substr(a, b));
//                        int C = stoi(s.substr(a+b, c));
//                        int D = stoi(s.substr(a+b+c, d));
//                        if (A<=255 && B<=255 && C<=255 && D<=255)
//                            if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
//                                ret.push_back(ans);
//                    }
//
//    return ret;
//}
int main(int argc, const char * argv[]) {
    vector<string> res = restoreIpAddresses("010010");
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}
