//
//  main.cpp
//  3. Longest Substring Without Repeating Characters
//
//  Created by Jie Lu on 14/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
#include <unordered_set>
using namespace std;

//O(n) solution:
int lengthOfLongestSubstring(string s) {
    unordered_set<int> bag;
    int i=0,j=0,maxL=0;
    while(j<s.length()){
        if(bag.find(s[j])==bag.end()){
            bag.insert(s[j++]);
            maxL=max(maxL,(int)bag.size());
        }
        else{
            bag.erase(s[i++]);
        }
    }
    return maxL;
}
//O(n^2) solution:
//int lengthOfLongestSubstring(string s) {
//    unordered_set<int> bag;
//    int i=0,j,maxL=0;
//    for(i=0;i<s.length();i++){
//        bag.clear();
//        for(j=i;j<s.length();j++){
//            if(bag.find(s[j])==bag.end())
//                bag.insert(s[j]);
//            else
//                break;
//        }
//        maxL=max(maxL,j-i);
//    }
//    return maxL;
//}
int main(int argc, const char * argv[]) {
    string s="dvdf";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
