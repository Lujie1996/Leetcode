//
//  main.cpp
//  332. Reconstruct Itinerary
//
//  Created by Jie Lu on 2018/5/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

// This solution is from internet.
// Multiset is a set but allow for duplicate numbers. All numbers are in-order stored.
//map<string, multiset<string>> targets;
//vector<string> route;
//void visit(string airport) {
//    while (targets[airport].size()) {
//        string next = *targets[airport].begin();
//        targets[airport].erase(targets[airport].begin());
//        visit(next);
//    }
//    route.push_back(airport);
//}
//vector<string> findItinerary(vector<pair<string, string>> tickets) {
//    for (auto ticket : tickets)
//        targets[ticket.first].insert(ticket.second);
//    visit("JFK");
//    return vector<string>(route.rbegin(), route.rend());
//}

// This is my original solution
int tryStartFrom(unordered_map<string, vector<string>>& trips, vector<string>& cur, string start, int totalTrips) {
    if (cur.size() == totalTrips + 1) {
        return 1;
    }
    if (trips.find(start) == trips.end() || trips[start].size() == 0) {
        return 0;
        // Must check if trips has a key 'start'. If straightly check trips[start].size(),
        // when there isn't key 'start', the map will create a key 'start' and assign it a default value 1.
        // This is fine for most cases. But when you are using iterator to walk through that map,
        // the extra space for 'start - 0' might trigger the whole map to be reallocated.
        // As the rule of thumb goes like this: Never change the container you are iteratoring within iteration.
    }
    for (auto &nextStart : trips[start]) {
        if (nextStart == "") {
            continue;
        }
        string tmp = nextStart;
        nextStart = "";
        cur.push_back(tmp);
        if (tryStartFrom(trips, cur, tmp, totalTrips)) {
            return 1;
        }
        cur.pop_back();
        nextStart = tmp;
    }
    return 0;
}
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, vector<string>> trips;
    for (auto ticket : tickets) {
        trips[ticket.first].push_back(ticket.second);
    }
    for (auto &start : trips) {
        sort(start.second.begin(), start.second.end());
    }
    vector<string> res;
    res.push_back("JFK");
    tryStartFrom(trips, res, "JFK", (int)tickets.size());
    return res;
}
int main(int argc, const char * argv[]) {
    vector<pair<string, string>> tickets{
//        make_pair("JFK","SFO"),
//        make_pair("JFK","ATL"),
//        make_pair("SFO","ATL"),
//        make_pair("ATL","JFK"),
//        make_pair("ATL","SFO")
        make_pair("MUC","LHR"),
        make_pair("JFK","MUC"),
        make_pair("SFO","SJC"),
        make_pair("LHR","SFO")
    };
    vector<string> res = findItinerary(tickets); // "JFK","ATL","JFK","SFO","ATL","SFO"
    for (auto s : res) {
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}
