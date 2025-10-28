// 215. Kth Largest Element in an Array
// URL: https://leetcode.com/problems/kth-largest-element-in-an-array
// Author: xianfeng.zhu@gmail.com

#include <queue>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

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

// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution4 {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) {
      return 0;
    }

    // Build max heap
    for (int i = 0; i < n; i++) {
      heapifyUp(nums, i);
    }

    while (--k > 0) {
      std::swap(nums[0], nums[--n]);
      heapifyDown(nums, 0, n);
    }

    return nums[0];
  }

  void heapifyUp(std::vector<int>& nums, int i) {
    if (i == 0) {
      return;
    }
    int p = (i - 1) / 2;
    if (nums[p] < nums[i]) {
      std::swap(nums[p], nums[i]);
      heapifyUp(nums, p);
    }
  }

  void heapifyDown(std::vector<int>& nums, int i, int n) {
    int l = i * 2 + 1;
    int r = l + 1;
    int c = l;
    if (r < n && nums[c] < nums[r]) {
      c = r;
    }
    if (c < n && nums[i] < nums[c]) {
      std::swap(nums[i], nums[c]);
      heapifyDown(nums, c, n);
    }
  }
};

TEST(Solution, findKthLargest) {
  std::vector<std::tuple<std::vector<int>, int, int>> cases = {
      {{3, 2, 1, 5, 6, 4}, 2, 5},
      {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4},
  };
  for (auto& [nums, k, ret] : cases) {
    EXPECT_EQ(Solution4().findKthLargest(nums, k), ret);
  }
}
