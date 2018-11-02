//
//  main.cpp
//  23. Merge k Sorted Lists
//
//  Created by Jie Lu on 2018/9/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
    ListNode* p = head;
    while(p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout<<endl;
}

// O(n^2), beats 12%
//int getMin(vector<ListNode*>& lists) {
//    int min = INT_MAX, index = -1;
//    for (int i = 0; i < lists.size(); i++) {
//        if (lists[i] && lists[i]->val < min) {
//            index = i;
//            min = lists[i]->val;
//        }
//    }
//    return index;
//}
//
//ListNode* mergeKLists(vector<ListNode*>& lists) {
//    int count = 0;
//    ListNode* res = new ListNode(1);
//    ListNode* p = res;
//    while (count != lists.size()) {
//        int minNode = getMin(lists);
//        if (minNode == -1) {
//            break;
//        }
//        p->next = lists[minNode];
//        p = p->next;
//        lists[minNode] = lists[minNode] == NULL ? NULL : lists[minNode]->next;
//        if (lists[minNode] == NULL) {
//            count++;
//        }
//    }
//    return res->next;
//}


// beats 80%.
// use max-heap to keep track of minimum list heads, O(nlgn)
struct cmp {
    bool operator() (const ListNode* a, const ListNode* b) const {
        return a && b && a->val > b->val; // max heap
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* res = new ListNode(1);
    ListNode* p = res;
    
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;
    for (auto list : lists) {
        if (list) {
            q.push(list);
        }
    }
    
    while (!q.empty()) {
        ListNode* minNode = q.top();
        q.pop();
        p->next = minNode;
        p = p->next;
        if (minNode->next) {
            q.push(minNode->next);
        }
    }
    return res->next;
}

int main(int argc, const char * argv[]) {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists{l1, l2, l3};
    
//    ListNode* l1 = NULL;
//    ListNode* l2 = NULL;
//    vector<ListNode*> lists{l1, l2};
    
    ListNode* sorted = mergeKLists(lists);
    printList(sorted);
    
    return 0;
}
