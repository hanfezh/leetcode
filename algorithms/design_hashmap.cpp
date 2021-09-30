/*
 * =====================================================================================
 *
 *       Filename:  design_hashmap.cpp
 *
 *    Description:  Design HasMap.
 *                  Design a HasMap without using amy built-in hash table libraries.
 *
 *        Version:  1.0
 *        Created:  02/26/19 01:49:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <utility>
#include <vector>

// Array
class MyHashMap1 {
 public:
  MyHashMap1() {
    size_ = 1000000 + 1;
    buf_ = new int[size_];
    std::fill_n(buf_, size_, -1);
  }

  ~MyHashMap1() { delete[] buf_; }

  void put(int key, int value) {
    if (key < size_) {
      buf_[key] = value;
    }
  }

  int get(int key) {
    if (key < size_) {
      return buf_[key];
    }
    return -1;
  }

  void remove(int key) {
    if (key < size_) {
      buf_[key] = -1;
    }
  }

 private:
  int size_;
  int* buf_;
};

// Hash table
class MyHashMap2 {
 private:
  using entity_pair = std::pair<int, int>;

 public:
  MyHashMap2() : buckets_(prime) {}

  ~MyHashMap2() = default;

  void put(int key, int value) {
    std::list<entity_pair>& bucket = getBucket(key);
    auto iter = bucket.begin();
    while (iter != bucket.end()) {
      if (iter->first == key) {
        iter->second = value;
        return;
      } else {
        iter++;
      }
    }
    bucket.push_back(std::make_pair(key, value));
  }

  int get(int key) {
    std::list<entity_pair>& bucket = getBucket(key);
    auto iter = bucket.begin();
    while (iter != bucket.end()) {
      if (iter->first == key) {
        return iter->second;
      } else {
        iter++;
      }
    }
    return -1;
  }

  void remove(int key) {
    std::list<entity_pair>& bucket = getBucket(key);
    auto iter = bucket.begin();
    while (iter != bucket.end()) {
      if (iter->first == key) {
        iter = bucket.erase(iter);
      } else {
        iter++;
      }
    }
  }

 private:
  std::list<entity_pair>& getBucket(int key) {
    const int hash = key % prime;
    return buckets_[hash];
  }

 private:
  const int prime = 997;
  std::vector<std::list<entity_pair>> buckets_;
};

using MyHashMap = MyHashMap2;

int main(int argc, char* argv[]) {
  MyHashMap my_map;
  my_map.put(10, 20);
  printf("%d\n", my_map.get(10));
  return 0;
}
