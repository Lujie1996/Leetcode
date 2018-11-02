//
//  main.cpp
//  857. Minimum Cost to Hire K Workers
//
//  Created by Jie Lu on 2018/10/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <cfloat>
#include <vector>
#include <queue>
using namespace std;

class Candidate {
public:
    int quality, wage;
    double ratio;
    
    Candidate(int a, int b) : quality(a), wage(b), ratio((double)a/b) {}
};

/*
 step 1, Sort all candidates according to the ratio of quality / wage in descending order;
 step 2, Use a fixed-size(K) heap to accommodate the candidates the highest ratio K candidates, ordered by their quality;
 step 3, Remove the highest quality candidate(heap top), insert the next highest ratio candidate to heap, update the minimum totalWage;
 step 4, Repeat step 3.
 
 Time complexity: O(nlgn)
 */
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    vector<Candidate> candidates;
    for (int i = 0; i < quality.size(); i++) {
        candidates.push_back(Candidate(quality[i], wage[i]));
    }
    
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {return a.ratio > b.ratio;});
    
    priority_queue<int> q;
    int totalQuality = 0;
    double res = DBL_MAX;
    
    for (int i = 0; i < candidates.size(); i++) {
        q.push(candidates[i].quality);
        totalQuality += candidates[i].quality;
        if (q.size() > K) {
            totalQuality -= q.top();
            q.pop(); // pop the candiadat with highest ability
        }
        if (q.size() == K) {
            res = min(res, totalQuality / candidates[i].ratio);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> quality{3,1,10,10,1}, wage{4,8,2,2,7};
    cout<<mincostToHireWorkers(quality, wage, 3)<<endl;
    return 0;
}
