//
//  main.cpp
//  770. Basic Calculator IV
//
//  Created by Jie Lu on 2018/9/18.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
    
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> eval;                // construct the map from evalvars to evalints
        for (int i = 0; i < evalvars.size(); ++i) {
            eval[evalvars[i]] = evalints[i];
        }
        
        auto resmp = helper(expression, eval);          // solve the problem
        vector<string> res;                             // construct the results
        for (auto param : resmp) {
            if (param.second == 0) {                    // skip zero coefficient
                continue;
            }
            res.push_back(to_string(param.second));
            for (auto p : param.first) {
                res.back() += "*" + p;
            }
        }
        return res;
    }
    
private:
    struct cmp {
        bool operator()(vector<string> x, vector<string> y) const {   // sort terms by degree
            if (x.size() == y.size()) {
                return x < y;
            }
            else {
                return x.size() > y.size();
            }
        }
    };
    
    map<vector<string>, int, cmp> helper(string &expr, unordered_map<string, int> &eval) {
        map<vector<string>, int, cmp> local = {{{}, 1}}, global;
        string sub = "";
        int sign = 1, n = (int)expr.size();
        
        for (int i = 0; i <= n; ++i) {
            if (i < n && expr[i] == ' ') {          // skip space
                continue;
            }
            if (i < n && isalnum(expr[i])) {        // number and alphabet, add to sub expression
                sub += expr[i];
            }
            else if (i < n && expr[i] == '(') {     // parenthesis
                ++i;
                for (int p = 1; ; ++i) {            // get the sub expression in parenthesis
                    if (expr[i] == '(') {
                        ++p;
                    }
                    else if (expr[i] == ')') {
                        --p;
                    }
                    if (p == 0) {
                        break;
                    }
                    sub += expr[i];  // not including the starting and ending brackets
                }
            } // until now, numbers, alphabets and expression within brackets are included in sub
            else {                                  // '+', '-', '*' or i == n
                if (sub.size() == n) {              // the whole expression is a number or variable
                    if (eval.count(sub)) {
                        return {{{}, eval[sub]}};   // variable is found in eval list
                    }
                    if (isdigit(sub[0])) {
                        return {{{}, stoi(sub)}};   // number
                    }
                    return {{{sub}, 1}};            // variable
                }
                
                map<vector<string>, int, cmp> mult, submp = helper(sub, eval);
                
                for (auto l : local) {              // multiply local with sub
                    for (auto r : submp) {
                        auto k = l.first;
                        k.insert(k.end(), r.first.begin(), r.first.end());
                        sort(k.begin(), k.end());
                        mult[k] += l.second * r.second; // mult = local * sub
                    }
                }
                local = mult;
                
                if (i == n || expr[i] != '*') {     // '+' or '-'
                    for (auto& t : local) {         // add local to global
                        global[t.first] += sign * t.second;
                    }
                    sign = i < n && expr[i] == '-' ? -1 : 1;
                    local = {{{}, 1}};              // reset local
                }
                sub = "";                           // reset sub
            }
        }
        return global;
    }
};

/*
 map<vector<string>, int>> : all the variables -> coefficent
 map<vector<string>, int>> local, global
 local: separate the expr with '+','-', calculate the result of the sub-expre
 global: use all locals to get the final result
 
 recursive:
 
 map helper(string s, map eval) {
     while (i < s.size()) {
         if s[i] is space, pass;
 
         else if s[i] is number or alphabet, string sub += s[i]
 
         else if s[i] is left parenthesis: get the whole content within parenthesis and attach it to sub
 
         else {
             // we meet s[i] == '+','-'
             if sub.size() == expr.size() : recursively call helper to get the 'local', which is the result of parsing(sub) -> submp
             multiply local with submp -> local
             if s[i] is '+' or '-' {
                 add local to global
                 reset local
             }
         }
     }
 }
 
 */

int main(int argc, const char * argv[]) {
    string s = "e + 8 - a + 5";
    vector<string> evalvars{"e"};
    vector<int> evalints{1};
    Solution obj;
    vector<string> res = obj.basicCalculatorIV(s,evalvars, evalints);
    for (auto s : res) {
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}
