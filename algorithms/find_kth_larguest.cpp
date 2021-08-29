// 215. Kth Largest Element in an Array
// URL: https://leetcode.com/problems/kth-largest-element-in-an-array
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

// Partition and sort
class Solution1 {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;
    k = nums.size() - k;
    while (true) {
      const int idx = partition(nums, left, right);
      if (idx < k) {
        left = idx + 1;
      } else if (idx > k) {
        right = idx - 1;
      } else {
        break;
      }
    }
    return nums[k];
  }

 private:
  int partition(std::vector<int>& nums, int left, int right) {
    const int pivot = right;
    while (left < right) {
      if (nums[left] < nums[pivot]) {
        left++;
      } else if (nums[right] >= nums[pivot]) {
        right--;
      } else {
        std::swap(nums[left], nums[right]);
      }
    }
    std::swap(nums[pivot], nums[left]);
    return left;
  }
};

// Min-heap using std::priority_queue
class Solution2 {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (const int val : nums) {
      min_heap.push(val);
      if (min_heap.size() > k) {
        min_heap.pop();
      }
    }
    return min_heap.top();
  }
};

// Min-heap default
template <class T, class Compare = std::less<T>>
class PriorityQueue {
 public:
  PriorityQueue() = default;

  void push(const T& val) {
    heap_.push_back(val);
    heapifyUp(heap_.size() - 1);
  }

  void pop() {
    heap_[0] = heap_.back();
    heap_.pop_back();
    if (heap_.size() > 0) {
      heapifyDown(0);
    }
  }

  const T& top() const { return heap_[0]; }

  size_t size() const { return heap_.size(); }

  bool empty() const { return (heap_.size() == 0); }

  void printHeap() const {
    for (const T& val : heap_) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

 private:
  void heapifyUp(const int index) {
    if (index == 0) {
      return;
    }

    const int parent = (index - 1) / 2;
    if (not compare_(heap_[parent], heap_[index])) {
      std::swap(heap_[parent], heap_[index]);
      heapifyUp(parent);
    }
  }

  void heapifyDown(const int index) {
    const int left = index * 2 + 1;
    const int right = index * 2 + 2;
    int child = left;
    if (right < heap_.size() && not compare_(heap_[left], heap_[right])) {
      child = right;
    }
    if (child < heap_.size() && not compare_(heap_[index], heap_[child])) {
      std::swap(heap_[index], heap_[child]);
      heapifyDown(child);
    }
  }

 private:
  std::vector<T> heap_;
  Compare compare_;
};

// Min-heap using PriorityQueue
class Solution3 {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    PriorityQueue<int> min_heap;
    for (const int val : nums) {
      min_heap.push(val);
      if (min_heap.size() > k) {
        min_heap.pop();
      }
    }
    return min_heap.top();
  }
};

using Solution = Solution3;

int main(int argc, char* argv[]) {
  std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  const int k = 4;
  const int kth = Solution().findKthLargest(nums, k);
  printf("Kth largest is %d\n", kth);
  return 0;
}
