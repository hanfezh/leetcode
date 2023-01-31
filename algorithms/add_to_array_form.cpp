/*
 * =====================================================================================
 *
 *       Filename:  add_to_array_form.cpp
 *
 *    Description:  989. Add to Array-Form of Integer.
 *                  https://leetcode.com/problems/add-to-array-form-of-integer/
 *
 *        Version:  1.0
 *        Created:  01/31/2023 21:38:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> arr;
    if (num.size() < 10) {
      arr.resize(11);
    } else {
      arr.resize(num.size() + 1);
    }

    auto fit = [&](const int i) {
      if ((i + 1 < arr.size()) && arr[i + 1] > 9) {
        arr[i + 1] -= 10;
        arr[i] += 1;
      }
    };

    int i = arr.size() - 1;
    int j = num.size() - 1;
    while (j >= 0 && k > 0) {
      arr[i--] = num[j--] + (k % 10);
      fit(i + 1);
      k /= 10;
    }
    while (j >= 0) {
      arr[i--] = num[j--];
      fit(i + 1);
    }
    while (k > 0) {
      arr[i--] = k % 10;
      fit(i + 1);
      k /= 10;
    }

    fit(i);
    if (arr[i] == 0) {
      i++;
    }

    return vector<int>(arr.begin() + i, arr.end());
  }
};

int main(int argc, char* argv[]) {
  vector<int> num = {2, 1, 5};
  int k = 806;
  vector<int> arr = Solution().addToArrayForm(num, k);
  for (const int n : arr) {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}
