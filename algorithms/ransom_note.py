#!/usr/bin/python
# -*- coding: utf-8 -*-
# 383. Ransom Note https://leetcode.com/problems/ransom-note/

import collections
import unittest

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        return not (collections.Counter(ransomNote) - collections.Counter(magazine))

class TestSolution(unittest.TestCase):
    def test_canConstruct(self):
        sol = Solution()
        self.assertFalse(sol.canConstruct('aa', 'ab'))
        self.assertTrue(sol.canConstruct('aa', 'aab'))

if __name__ == '__main__':
    unittest.main()
