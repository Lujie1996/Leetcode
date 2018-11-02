//
//  main.cpp
//  833. Find And Replace in String
//
//  Created by Jie Lu on 2018/10/21.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
    vector<pair<int, vector<string>>> m;
    for (int i = 0; i < indexes.size(); i++) {
        vector<string> t{sources[i], targets[i]};
        m.push_back({indexes[i], t});
    }
    sort(m.begin(), m.end(), [](const pair<int, vector<string>>& a, pair<int, vector<string>>& b) {return a.first < b.first;});
    
    string res;
    int pre = 0;
    for (int i = 0; i < m.size(); i++) {
        int index = m[i].first;
        string source = m[i].second[0];
        string target = m[i].second[1];
        bool changed = false;
        
        if (index + source.size() <= S.size()) {
            string sub = S.substr(index, source.size());
            if (sub == source) {
                res += S.substr(pre, index-pre);
                res += target;
                changed = true;
            }
        }
        if (changed) {
            pre = index + (int)source.size();
        }
    }
    res += S.substr(pre);
    return res;
}

int main(int argc, const char * argv[]) {
    /*
     "abcd"
     [0, 2]
     ["a", "cd"]
     ["eee", "ffff"]
     */
    vector<int> indexes{0,2};
    vector<string> sources{"ab","ec"}, targets{"eee","ffff"};
    cout<<findReplaceString("abcd", indexes, sources, targets)<<endl;
    return 0;
}
