// 295. Find Median from Data Stream: https://leetcode.com/problems/find-median-from-data-stream/
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <vector>

// Time limit exceeded
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

using MedianFinder = MedianFinder2;

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
