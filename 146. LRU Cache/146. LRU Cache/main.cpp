//
//  main.cpp
//  146. LRU Cache
//
//  Created by Jie Lu on 2018/12/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    unordered_map<int, list<pair<int,int>>::iterator> keyList;
    list<pair<int,int>> cache;
    int capacity_;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto ite = keyList.find(key);
        // find() returns an iterator
        if (ite == keyList.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, ite->second);
        return ite->second->second;
    }
    
    void put(int key, int value) {
        auto ite = keyList.find(key);
        if (ite != keyList.end()) {
            ite->second->second = value;
            cache.splice(cache.begin(), cache, ite->second);
            return;
        }
        
        if (capacity_ == cache.size()) {
            auto lastNode = cache.back();
            // back() returns the reference to that element, not an iterator
            // begin() and end() are iterator typed.
            keyList.erase(lastNode.first);
            cache.pop_back();
        }
        
        cache.emplace_front(key, value);
        keyList[key] = cache.begin();
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
