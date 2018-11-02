//
//  main.cpp
//  142. Linked List Cycle II
//
//  Created by Jie Lu on 2018/4/23.
//  Copyright © 2018 Jie Lu. All rights reserved.
//
/*
 L1: distance from head to the entry point of cycle
 L2: distance from the entry point to meeting point
 C: number of points in the cycle
 When the slow pointer enters the cycle, if the cycle is long enough, the fast pointer is L1 points ahead of slow.
 Then the chase within cycle starts. The slow walks L2 steps and the fast walks 2 * L2 steps.
 We have this equation: place of fast + steps that fast walked - n loops == steps that slow walked, that is :
 L1 + 2 * L2 - n * C == L2   ===>    L1 + L2 == n * C
 ******IMPORTANT CONCLUSION******: distance from meeting point to entry point along the forward direction == L1
 If there is only one loop, then L1 + L2 == C, or L1 = C - L2
 Therefore, if we start from the meeting point, let A start from head and B start from meeting point, both walks by one step,
 then A and b shall meet at the entry point of the cycle.
 */
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head,*fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;               //Slow moves by 1 step
        fast = fast->next->next;        //Fast moves by two steps
        //If they meet then there is a loop
        if(slow == fast)
        {
            //To find the starting element where the loop starts
            fast = fast;
            slow = head;
            while(slow != fast)
            {
                //Both move by 1 step
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
