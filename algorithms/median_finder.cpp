// 295. Find Median from Data Stream: https://leetcode.com/problems/find-median-from-data-stream/
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <queue>
#include <vector>

// Time limit exceeded
// O(n) add, O(1) find
class MedianFinder1 {
 public:
  MedianFinder1() {}

  void addNum(int num) {
    auto iter = nums_.begin();
    while (iter != nums_.end() && *iter < num) {
      iter++;
    }
    nums_.insert(iter, num);
  }

  double findMedian() {
    int mid = nums_.size() / 2;
    if ((nums_.size() % 2) != 0) {
      return nums_[mid];
    }
    return ((nums_[mid - 1] + nums_[mid]) / 2.0);
  }

 private:
  std::vector<int> nums_;
};

// Time limit exceeded
// O(1) add, O(nlogn) find
class MedianFinder2 {
 public:
  MedianFinder2() {}

  void addNum(int num) {
    nums_.push_back(num);
    ordered_ = false;
  }

  double findMedian() {
    if (ordered_) {
      return median_;
    }

    const int left = 0;
    const int right = nums_.size() - 1;
    int mid = (left + right) / 2;
    int idx = partition(nums_, left, right);
    while (idx != mid) {
      if (idx < mid) {
        idx = partition(nums_, idx + 1, right);
      } else {
        idx = partition(nums_, left, idx - 1);
      }
    }

    ordered_ = true;
    if ((nums_.size() % 2) != 0) {
      // Return the middle value
      median_ = nums_[mid];
      return median_;
    }

    // Find the minimum in right part
    int rmin = nums_[right];
    for (int i = mid + 1; i < right; i++) {
      rmin = std::min(rmin, nums_[i]);
    }
    // Return the mean of two middle values
    median_ = (nums_[mid] + rmin) / 2.0;
    return median_;
  }

 private:
  int partition(std::vector<int>& arr, int left, int right) {
    int key = right;
    while (left < right) {
      if (arr[left] < arr[key]) {
        left++;
      } else if (arr[right] >= arr[key]) {
        right--;
      } else {
        std::swap(arr[left], arr[right]);
      }
    }
    std::swap(arr[left], arr[key]);
    return left;
  }

 private:
  std::vector<int> nums_;
  bool ordered_ = false;
  double median_ = 0.0;
};

// Time limit exceeded, std::sort
// O(1) add, O(nlogn) find
class MedianFinder3 {
 public:
  MedianFinder3() {}

  void addNum(int num) {
    nums_.push_back(num);
  }

  double findMedian() {
    std::sort(nums_.begin(), nums_.end());
    int mid = nums_.size() / 2;
    if ((nums_.size() % 2) != 0) {
      return nums_[mid];
    }
    return ((nums_[mid - 1] + nums_[mid]) / 2.0);
  }

 private:
  std::vector<int> nums_;
};

// Time limit exceeded
// O(logn) add, O(1) find
class MedianFinder4 {
 public:
  MedianFinder4() {}

  void addNum(int num) {
    int left = 0;
    int right = nums_.size() - 1;
    int idx = 0;
    while (left <= right) {
      idx = (left + right) / 2;
      if (nums_[idx] < num) {
        left = idx + 1;
      } else if (nums_[idx] > num) {
        right = idx - 1;
      } else {
        break;
      }
    }
    if (idx < nums_.size() && nums_[idx] < num) {
      idx++;
    }

    // Insert at idx
    auto iter = nums_.begin();
    while (idx-- > 0) {
      iter++;
    }
    nums_.insert(iter, num);
  }

  double findMedian() {
    std::sort(nums_.begin(), nums_.end());
    int mid = nums_.size() / 2;
    if ((nums_.size() % 2) != 0) {
      return nums_[mid];
    }
    return ((nums_[mid - 1] + nums_[mid]) / 2.0);
  }

 private:
  std::vector<int> nums_;
};

// Accepted, std::priority_queue
// O(logn) add, O(1) find
class MedianFinder5 {
 public:
  MedianFinder5() {}

  void addNum(int num) {
    // Push to large queue
    small_queue_.push(num);
    large_queue_.push(-small_queue_.top());
    small_queue_.pop();

    // Keep small queue's size bigger than large queue
    if (small_queue_.size() < large_queue_.size()) {
      small_queue_.push(-large_queue_.top());
      large_queue_.pop();
    }
  }

  double findMedian() {
    if (small_queue_.size() > large_queue_.size()) {
      return small_queue_.top();
    }
    return ((small_queue_.top() - large_queue_.top()) / 2.0);
  }

 private:
  std::priority_queue<int> small_queue_;
  std::priority_queue<int> large_queue_;
};

using MedianFinder = MedianFinder5;

int main(int argc, char* argv[]) {
  MedianFinder finder;
  finder.addNum(-1);
  finder.addNum(-2);
  finder.addNum(-3);
  finder.addNum(-4);
  printf("Median is %f\n", finder.findMedian());
  finder.addNum(-5);
  printf("Median is %f\n", finder.findMedian());
  return 0;
}
