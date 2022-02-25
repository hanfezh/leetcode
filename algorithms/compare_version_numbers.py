#!/usr/bin/python
# -*- coding: utf-8 -*-
# 165. Compare Version Numbers https://leetcode.com/problems/compare-version-numbers/

import unittest

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        revisions1 = [int(i) for i in version1.split('.')]
        revisions2 = [int(i) for i in version2.split('.')]
        size = max(len(revisions1), len(revisions2))
        for i in range(size):
            v1 = revisions1[i] if i < len(revisions1) else 0
            v2 = revisions2[i] if i < len(revisions2) else 0
            if v1 < v2:
                return -1
            elif v1 > v2:
                return 1
        return 0

class TestSolution(unittest.TestCase):
    def test_compareVersion(self):
        sol = Solution()
        self.assertEqual(sol.compareVersion('1.01', '1.001'), 0)
        self.assertEqual(sol.compareVersion('1.0', '1.0.0'), 0)
        self.assertEqual(sol.compareVersion('0.1', '1.1'), -1)

if __name__ == '__main__':
    unittest.main()
