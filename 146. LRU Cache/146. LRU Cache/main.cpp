//
//  main.cpp
//  146. LRU Cache
//
//  Created by Jie Lu on 2018/12/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        Node *prev, *next;
        int key, value;
        Node(int a, int b, Node* p, Node* q) : key(a), value(b), prev(p), next(q) {}
    };
    
private:
    unordered_map<int, Node*> cached;
    Node *dummyHead = new Node(0, 0,NULL,NULL), *lastNode = NULL;
    int used = 0, capacity = 0;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cached.find(key) == cached.end()) {
            return -1;
        }
        else {
            Node* node = cached[key];
            deleteNode(node);
            insertHead(node);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        if (cached.find(key) != cached.end()) {
            deleteNode(cached[key]);
        }
        else if (used >= capacity && lastNode) {
            Node* preLastNode = preLastNode = lastNode->prev;
            cached.erase(lastNode->key);
            deleteNode(lastNode);
            lastNode = preLastNode;
        }
        Node* node = new Node(key, value, lastNode, dummyHead->next);
        if (dummyHead->next == NULL) {
            lastNode = node;
        }
        insertHead(node);
        cached[key] = node;
        used++;
    }
    
    void deleteNode(Node* node) {
        if (node == NULL) {
            return;
        }
        if (dummyHead->next == node) {
            lastNode = NULL;
        }
        else {
            lastNode = node->prev;
        }
        Node *next = node->next;
        node->prev->next = next;
    }
    
    void insertHead(Node* node) {
        Node* next = dummyHead->next;
        dummyHead->next = node;
        if (next)
            next->prev = node;
        node->next = next;
        node->prev = dummyHead;
        if (lastNode == NULL) {
            lastNode = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(int argc, const char * argv[]) {
    
    /*
     ["LRUCache","put","put","get","put","put","get"]
     [[2],        [2,1],[2,2],[2],  [1,1],[4,1],[2]]
     */
    LRUCache obj(2);
    obj.put(2, 1);
    obj.put(2, 2);
    cout<<obj.get(2)<<endl;
    obj.put(1, 1);
    obj.put(4, 2);
    cout<<obj.get(2)<<endl;
    
    /*
     ["LRUCache","put","put","get","put","get","put","get","get","get"]
     [[2],        [1,1],[2,2],[1],  [3,3],[2],  [4,4],[1],  [3],  [4]]
     */
//    LRUCache cache(2);
//    cache.put(1, 1);
//    cache.put(2, 2);
//    cout<<cache.get(1)<<endl;
//    cache.put(3,3);
//    cout<<cache.get(2)<<endl;
//    cache.put(4,4);
//    cout<<cache.get(1)<<endl;
//    cout<<cache.get(3)<<endl;
//    cout<<cache.get(4)<<endl;
    
    /*
     ["LRUCache","put","get"]
     [[1],[2,1],[2]]
     */
//    LRUCache cache(1);
//    cache.put(2, 1);
//    cout<<cache.get(2)<<endl;
    
    /*
     ["LRUCache","put","get","put","get","get"]
     [ [1],       [2,1],[2],  [3,2],[2],  [3]]
     */
//    LRUCache cache(1);
//    cache.put(2, 1);
//    cout<<cache.get(2)<<endl;
//    cache.put(3, 2);
//    cout<<cache.get(2)<<endl;
//    cout<<cache.get(3)<<endl;
    return 0;
}
