//
//  main.cpp
//  406. Queue Reconstruction by Height
//
//  Created by Jie Lu on 2018/7/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// My original solution
//vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
//    sort(people.begin(), people.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {return a.second < b.second;});
//    vector<pair<int, int>> res;
//    for (int i = 0; i < people.size(); i++) {
//        int count = 0, j = 0;
//        while (count < people[i].second) {
//            if (res[j].first >= people[i].first) {
//                count++;
//            }
//            j++;
//        }
//        while (j < res.size() && res[j].first < people[i].first) {
//            j++;
//            // test case: [[1,0],[2,0]], when comes to [2,0], it should go over all numbers which are smaller than it.
//            // otherwise it will change the k of those pairs.
//        }
//        res.insert(res.begin()+j, people[i]);
//    }
//    return res;
//}

// solution from BBS. This is more concise.
// observation
// we can place the people in decreasing order regarding to height,
// tie break by increasing order with regard to ppl in
// then insert (read code)
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
{
    sort(people.begin(), people.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
             if (a.first == b.first)
                 return a.second < b.second;
             return a.first > b.first;
         });
    // After this sort, we have people: [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]
    vector<pair<int, int>> ans;
    for (auto p : people) {
        ans.insert(ans.begin() + p.second, p);
        // Since we pick up pairs one-by-one from the sorted 'people', every time when it comes to current p, it holds that
        // all numbers in ans have greater height than current, therefore simply insert according to index(p.second) can just ensure that k is correct.
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    // [7,0], [4,4], [7,1], [5,0], [6,1], [5,2]
    // after reconstruction should be:
    // [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
    vector<pair<int, int>> people;
    people.push_back(make_pair(7, 0));
    people.push_back(make_pair(4, 4));
    people.push_back(make_pair(7, 1));
    people.push_back(make_pair(5, 0));
    people.push_back(make_pair(6, 1));
    people.push_back(make_pair(5, 2));
    vector<pair<int, int>> res = reconstructQueue(people);
    for (auto one : res) {
        cout<<"["<<one.first<<","<<one.second<<"]"<<" ";
    }
    cout<<endl;
    return 0;
}
