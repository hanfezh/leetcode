/*
 * =====================================================================================
 *
 *       Filename:  design_hashset.cpp
 *
 *    Description:  Design HashSet.
 *                  Design a HashSet without using any built-in hash table libraries.
 *
 *        Version:  1.0
 *        Created:  02/25/19 10:59:29
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
#include <list>
#include <vector>

// Bit manipulation
class MyHashSet1 {
 public:
  MyHashSet1() {
    size_ = (1000000 + 1 + 31) / 32;
    buf_ = new int[size_]();
  }

  ~MyHashSet1() { delete[] buf_; }

  void add(int key) {
    int idx = key / 32;
    int seq = key % 32;
    if (idx < size_) {
      buf_[idx] |= (0x1 << seq);
    }
  }

  void remove(int key) {
    int idx = key / 32;
    int seq = key % 32;
    if (idx < size_) {
      buf_[idx] &= ~(0x1 << seq);
    }
  }

  bool contains(int key) {
    int idx = key / 32;
    int seq = key % 32;
    if (idx < size_) {
      return ((buf_[idx] & (0x1 << seq)) ? true : false);
    }
    return false;
  }

 private:
  int size_;
  int* buf_;
};

// Hash table
class MyHashSet2 {
 public:
  MyHashSet2() : buckets_(prime) {}

  ~MyHashSet2() = default;

  void add(int key) {
    std::list<int>& nums = getBucket(key);
    for (const int val : nums) {
      if (val == key) {
        return;
      }
    }
    nums.push_back(key);
  }

  void remove(int key) {
    std::list<int>& nums = getBucket(key);
    nums.remove(key);
  }

  bool contains(int key) {
    std::list<int>& nums = getBucket(key);
    for (const int val : nums) {
      if (val == key) {
        return true;
      }
    }
    return false;
  }

 private:
  std::list<int>& getBucket(int key) {
    int hash = key % prime;
    return buckets_[hash];
  }

 private:
  const int prime = 997;
  std::vector<std::list<int>> buckets_;
};

using MyHashSet = MyHashSet2;

int main(int argc, char* argv[]) {
  MyHashSet my_set;
  my_set.add(10);
  printf("%d\n", my_set.contains(10));
  return 0;
}
