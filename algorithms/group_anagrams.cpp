/*
 * =====================================================================================
 *
 *       Filename:  group_anagrams.cpp
 *
 *    Description:  49. Group Anagrams. 
 *                  Given an array of strings, group anagrams together.
 *
 *        Version:  1.0
 *        Created:  05/09/2019 12:59:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> anagram_map;
        for (auto& s: strs)
        {
            auto key = getAnagramKey(s);
            auto ret_pair = anagram_map.insert(std::make_pair(key, std::vector<std::string>({s})));
            if (!ret_pair.second)
            {
                ret_pair.first->second.push_back(s);
            }
        }

        std::vector<std::vector<std::string>> anagram_vect;
        for (auto& item: anagram_map)
        {
            anagram_vect.push_back(item.second);
        }

        return anagram_vect;
    }

private:
    std::string getAnagramKey(const std::string& str)
    {
        const int letter_size = 26;
        int counts[letter_size] = {0};
        for (char chr: str)
        {
            counts[chr - 'a'] += 1;
        }

        std::string key;
        for (int i = 0; i < letter_size; i++)
        {
            if (counts[i] > 0)
            {
                key.append(counts[i], (char)(i + 'a'));
            }
        }

        return key;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto anagrams = Solution().groupAnagrams(strs);
    printf("Group size of anagrams: %zd\n", anagrams.size());
    return 0;
}
