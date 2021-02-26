// 524. Longest Word in Dictionary through Deleting
// Refer: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  std::string findLongestWord(std::string& str, std::vector<std::string>& dictionary) {
    auto str_cmp = [](const std::string& a, const std::string& b) -> bool {
      if (a.size() != b.size()) {
        return (a.size() > b.size());
      } else {
        return a < b;
      }
    };

    // Sort dictionary
    std::sort(dictionary.begin(), dictionary.end(), str_cmp);

    for (const std::string& word: dictionary) {
      if (containWord(str, word)) {
        return word;
      }
    }
    return std::string();
  }

 private:
  bool containWord(const std::string& str, const std::string& word) {
    int i = 0;
    int j = 0;
    while (i < str.size() && j < word.size() && (str.size() - i >= word.size() - j)) {
      if (str[i] == word[j]) {
        i++;
        j++;
      } else {
        i++;
      }
    }
    return (j == word.size());
  }
};

int main(int argc, char* argv[]) {
  std::string str = "abpcplea";
  std::vector<std::string> dictionary = {"ale", "apple", "monkey", "plea"};
  std::string longest = Solution().findLongestWord(str, dictionary);
  printf("Longest word => %s\n", longest.c_str());
  return 0;
}
