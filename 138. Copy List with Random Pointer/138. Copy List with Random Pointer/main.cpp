//
//  main.cpp
//  138. Copy List with Random Pointer
//
//  Created by Jie Lu on 2018/5/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//RandomListNode *copyRandomList(RandomListNode *head) {
//    if (head == NULL)
//        return NULL;
//    vector<RandomListNode*> nodes;
//    unordered_map<RandomListNode*, int> nodeIndex;
//    // This is critical part of this solution. Map node address to its index.
//    RandomListNode* p = head;
//    int i = 0;
//    while (p) {
//        nodes.push_back(new RandomListNode(p->label));
//        nodeIndex[p] = i++;
//        p = p->next;
//    }
//
//    RandomListNode* pre = nodes[0];
//    for (auto node : nodes) {
//        if (node == nodes[0]) {
//            continue;
//        }
//        pre->next = node;
//        pre = node;
//    }
//
//    p = head;
//    for (auto node : nodes) {
//        if (p->random == NULL) {
//            node->random = NULL;
//        }
//        else {
//            i = nodeIndex[p->random];
//            node->random = nodes[i];
//        }
//        p = p->next;
//    }
//    return nodes[0];
//}

RandomListNode* copyRandomList(RandomListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    unordered_map<RandomListNode*, RandomListNode*> oldNew;
    RandomListNode *p = head, *q = new RandomListNode(head->label), *newHead = q;
    oldNew[p] = q;
    oldNew[NULL] = NULL;
    while (p->next) {
        q->next = new RandomListNode(p->next->label);
        oldNew[p->next] = q->next;
        p = p->next;
        q = q->next;
    }
    
    p = head;
    q = newHead;
    while (p) {
        q->random = oldNew[p->random];
        p = p->next;
        q = q->next;
    }

    return newHead;
}

int main(int argc, const char * argv[]) {
    RandomListNode *a = new RandomListNode(4), *b = new RandomListNode(2), *c = new RandomListNode(5);
    a->next = b;
    b->next = c;
    c->next = NULL;
    a->random = c;
    b->random = a;
    c ->random = b;
    RandomListNode *res = copyRandomList(a);
    while (res) {
        if (res->next) {
            cout<<"label: "<<res->label<<", next: "<<res->next->label<<", random: "<<res->random->label<<endl;
        }
        else {
            cout<<"label: "<<res->label<<", next: NULL, random: "<<res->random->label<<endl;
        }
        res = res->next;
    }
    return 0;
}
