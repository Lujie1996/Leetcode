//
//  main.cpp
//  911. Online Election
//
//  Created by Jie Lu on 2018/10/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TopVotedCandidate {
private:
    unordered_map<int, int> count;
    vector<pair<int, int>> winner; // the winner from time i is j
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int m = 0; // the number of votes of current winner
        int w = -1; // index of current winner
        for (int i = 0; i < times.size(); i++) {
            count[persons[i]] += 1;
            if (count[persons[i]] >= m) {
                m = count[persons[i]];
                if (persons[i] != w) {
                    w = persons[i];
                    winner.push_back({times[i], persons[i]});
                }
            }
        }
    }
    
    int q(int t) {
        if (t >= winner.back().first) {
            return winner.back().second;
        }
        int low = 0, high = (int)winner.size() - 1, mid = 0;
        while (low < high) {
            mid = (low + high) / 2;
            if (winner[mid].first == t) {
                break;
            }
            else if (winner[mid].first > t) {
                
                high = mid;            }
            else {
                low = mid + 1;
            }
        }
        if (low < high) {
            return winner[mid].second;
        }
        else {
            return low - 1 >= 0 ? winner[low-1].second : winner[low].second;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> persons{0,1,0,1,1}, times{24,29,31,76,81}, q{28,24,29,77,30,25,76,75,81,80};
    TopVotedCandidate obj = TopVotedCandidate(persons, times);
    for (auto a : q) {
        cout<<obj.q(a)<<endl;
    }
    return 0;
}
