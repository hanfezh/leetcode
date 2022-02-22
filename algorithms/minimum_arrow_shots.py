#!/usr/bin/python
# -*- coding: utf-8 -*-
# 452. Minimum Number of Arrows to Burst Balloons
# https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

import unittest
from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        shots = 1
        right = points[0][1]
        for p in points:
            if p[0] <= right:
                continue
            else:
                right = p[1]
                shots += 1
        return shots

class TestSolution(unittest.TestCase):
    def test_findMinArrowShots(self):
        sol = Solution()
        self.assertEqual(sol.findMinArrowShots([[10, 16], [2, 8], [1, 6], [7, 12]]), 2)
        self.assertEqual(sol.findMinArrowShots([[1, 2], [3, 4], [5, 6], [7, 8]]), 4)
        self.assertEqual(sol.findMinArrowShots([[1, 2], [2, 3], [3, 4], [4, 5]]), 2)

if __name__ == '__main__':
    unittest.main()
