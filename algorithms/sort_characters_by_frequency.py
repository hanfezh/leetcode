#!/usr/bin/python
# -*- coding: utf-8 -*-
# 451. Sort Characters By Frequency
# https://leetcode.com/problems/sort-characters-by-frequency/

import collections
import unittest

class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join(c * n for c, n in collections.Counter(s).most_common())

class TestSolution(unittest.TestCase):
    def test_frequencySort(self):
        sol = Solution()
        self.assertEqual(sol.frequencySort('tree'), 'eetr')
        self.assertEqual(sol.frequencySort('cccaaa'), 'cccaaa')
        self.assertEqual(sol.frequencySort('Aabb'), 'bbAa')

if __name__ == '__main__':
    unittest.main()
