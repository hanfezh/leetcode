#!/usr/bin/python
# -*- coding: utf-8 -*-
# 392. Is Subsequence https://leetcode.com/problems/is-subsequence/

import unittest

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False
        i = 0
        for c in s:
            i = t.find(c, i)
            if i == -1:
                return False
            i += 1
        return True

class TestSolution(unittest.TestCase):
    def test_isSubsequence(self):
        sol = Solution()
        self.assertTrue(sol.isSubsequence('abc', 'ahbgdc'))
        self.assertFalse(sol.isSubsequence('axc', 'ahbgdc'))

if __name__ == '__main__':
    unittest.main()
