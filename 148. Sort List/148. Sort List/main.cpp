//
//  main.cpp
//  148. Sort List
//
//  Created by Jie Lu on 2018/5/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void insertListNode(ListNode* head) {
    int x;
    cin >> x;
    if (x == 0) {
        head = NULL;
        return;
    }
    head->next = new ListNode(x);
    insertListNode(head->next);
}
void printList(ListNode* head) {
    ListNode* p = head;
    while(p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout<<endl;
}

/* This is quick sort of array
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}
void qsort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(nums, low, high);
        qsort(nums, low, pivotIndex-1);
        qsort(nums, pivotIndex+1, high);
    }
}
 */

/* This is merge sort of array
void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> tmp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (nums[i] < nums[j]) {
            tmp.push_back(nums[i]);
            i++;
        }
        else {
            tmp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid) {
        tmp.push_back(nums[i]);
        i++;
    }
    while (j <= high) {
        tmp.push_back(nums[j]);
        j++;
    }
    for (int i = 0; low + i <= high; i++) {
        nums[low+i] = tmp[i];
    }
}
void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}
 */

/* This is merge sort of linked list
ListNode* merge( ListNode* head1 , ListNode * head2){
    ListNode* d = new ListNode (0);            // dummy node
    ListNode* e = d;
    while(head1 || head2){
        if(head1 && (!head2 || head1->val <= head2 -> val) ){
            e = e->next = head1 ;
            head1 = head1 -> next;
        }
        if(head2 && (!head1 || head2->val < head1 -> val) ){
            e = e->next = head2 ;
            head2 = head2 -> next;
        }
    }
    e->next = NULL;
    return d->next;
}
ListNode* sortList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode* slow = head;
    ListNode* fast =head->next;
    while(fast && fast->next){         // to find middle node
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* headb = slow->next;     // headb is start of 2nd half of list
    slow->next = NULL;
    return merge(sortList(head) , sortList(headb));
}
*/

/* This is quick sort of linked list.*/
// pivot: head ListNode. Idea: two pointers p and q.
// Nodes prior to p have smaller key value than pivot. p traverses and swap with p when it meets a small Node.
ListNode* GetPartion(ListNode* pBegin, ListNode* pEnd)
{
    int key = pBegin->val;
    ListNode* p = pBegin;
    ListNode* q = p->next;
    
    while(q != pEnd)
    {
        if(q->val < key)
        {
            p = p->next;
            swap(p->val, q->val);
        }
        q = q->next;
    }
    swap(p->val,pBegin->val);
    return p;
}
void QuickSort(ListNode* pBeign, ListNode* pEnd)
{
    if(pBeign != pEnd)
    {
        ListNode* partion = GetPartion(pBeign,pEnd);
        QuickSort(pBeign,partion);
        QuickSort(partion->next,pEnd);
    }
}
ListNode* sortList(ListNode* head) {
    ListNode* newHead = new ListNode(0);
    newHead->next = head;
    QuickSort(newHead->next, NULL);
    return newHead->next;
}

int main(int argc, const char * argv[]) {
//    vector<int> nums{3,5,2,1,8,4}; // 1 2 3 4 5 8
//    qsort(nums, 0, (int)nums.size()-1);
//    mergeSort(nums, 0, (int)nums.size()-1);
//    for (auto num : nums) {
//        cout<<num<<" ";
//    }
//    cout<<endl;
    ListNode* node0 = new ListNode(3);
    ListNode* node1 = new ListNode(5);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(8);
    ListNode* node5 = new ListNode(4);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    printList(sortList(node1));
    return 0;
}
