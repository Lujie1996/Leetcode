//
//  main.cpp
//  621. Task Scheduler
//
//  Created by Jie Lu on 2018/8/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// This solution passed 58/64 test cases. Idk where the problem is.
//int leastInterval(vector<char>& tasks, int n) {
//    unordered_map<char, int> taskCount;
//    for (auto task : tasks) {
//        taskCount[task] += 1;
//    }
//    vector<int> taskNum;
//    for (auto t : taskCount) {
//        taskNum.push_back(t.second);
//    }
//    sort(taskNum.begin(), taskNum.end());
//    reverse(taskNum.begin(), taskNum.end());
//    int res = 0, count = 0;
//    while (count < tasks.size()) {
//        int picked = 0;
//        for (int i = 0; i <= n; i++) {
//            if (count == tasks.size()) {
//                break;
//            }
//            while (picked < taskNum.size() && taskNum[picked] == 0) {
//                picked++;
//            }
//            if (picked == taskNum.size()) {
//                res += 1;
//            }
//            else {
//                taskNum[picked]--;
//                count++;
//                res++;
//                picked++;
//            }
//        }
//    }
//    return res;
//}

// Accepted. Beats 40%. Two queues: q and taskToEnQ.
//int leastInterval(vector<char>& tasks, int n) {
//    unordered_map<char, int> taskCount;
//    for (auto task : tasks) {
//        taskCount[task] += 1;
//    }
//    priority_queue<int> tasksToEnQ;
//    for (auto t : taskCount) {
//        tasksToEnQ.push(t.second);
//    }
//    queue<int> q;
//    while (q.size() <= n && !tasksToEnQ.empty()) {
//        q.push(tasksToEnQ.top());
//        tasksToEnQ.pop();
//    }
//    while (q.size() <= n) {
//        q.push(-1);
//    }
//    int count = 0, res = 0;
//    while (count < tasks.size()) {
//        int front = q.front();
//        q.pop();
//        if (front == -1) {
//            res++;
//            q.push(-1);
//            continue;
//        }
//        count++;
//        res++;
//        front -= 1;
//        if (tasksToEnQ.empty()) {
//            if (front > 0) {
//                q.push(front);
//            }
//            else {
//                q.push(-1);
//            }
//        }
//        else {
//            if (front < tasksToEnQ.top()) {
//                q.push(tasksToEnQ.top());
//                tasksToEnQ.pop();
//                if (front > 0) {
//                    tasksToEnQ.push(front);
//                }
//            }
//            else {
//                q.push(front);
//            }
//        }
//    }
//    return res;
//}

// From Discuss. Very concise.
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> mp;
    int count = 0;
    for (auto e : tasks)
    {
        mp[e]++;
        count = max(count, mp[e]);
    }
    int ans = (count-1)*(n+1);
    for (auto e : mp)
        if (e.second == count)
            ans++;
    return max((int)tasks.size(), ans);
}

int main(int argc, const char * argv[]) {
//    vector<char> tasks1{'A','A','A','B','B','B'};
    vector<char> tasks2{'A','A','A','A','A','A','B','C','D','E','F','G'};
//    cout<<leastInterval(tasks1, 2)<<endl;
    cout<<leastInterval(tasks2, 2)<<endl;
//    cout<<leastInterval(tasks3, 36)<<endl;
    return 0;
}
