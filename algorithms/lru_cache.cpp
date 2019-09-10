// =====================================================================================
//
//       Filename:  lru_cache.cpp
//
//    Description:  146. LRU Cache. 
//                  Design and implement a data structure for Least Recently Used (LRU) 
//                  cache. It should support the following operations: get and put.
//
//        Version:  1.0
//        Created:  09/09/2019 08:32:57 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <list>
#include <unordered_map>

class LRUCache
{
public:
    LRUCache(int capacity): capacity_(capacity)
    {
    }
    
    int get(int key)
    {
        auto iter = cache_map_.find(key);
        if (iter != cache_map_.end())
        {
            keep(iter);
            return iter->second.first;
        }

        return -1;
    }
    
    void put(int key, int value)
    {
        auto iter = cache_map_.find(key);
        if (iter != cache_map_.end())
        {
            key_list_.erase(iter->second.second);
        }
        else if (cache_map_.size() == capacity_)
        {
            cache_map_.erase(key_list_.back());
            key_list_.pop_back();
        }

        key_list_.push_front(key);
        cache_map_[key] = std::make_pair(value, key_list_.begin());
    }

private:
    using LinkedList = std::list<int>;
    using CacheValue = std::pair<int, LinkedList::iterator>;
    using CacheMap = std::unordered_map<int, CacheValue>;

    void keep(CacheMap::iterator iter)
    {
        key_list_.erase(iter->second.second);
        key_list_.push_front(iter->first);
        iter->second.second = key_list_.begin();
    }

private:
    int capacity_;
    LinkedList key_list_;
    CacheMap cache_map_;
};

int main(int argc, char* argv[])
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    printf("get(2) -> %d\n", cache.get(2));
    return 0;
}
