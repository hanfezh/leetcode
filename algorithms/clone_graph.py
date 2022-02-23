#!/usr/bin/python
# -*- coding: utf-8 -*-
# 133. Clone Graph https://leetcode.com/problems/clone-graph/

import collections

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

# BFS
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        all_nodes = {node.val: Node(node.val)}
        queue = collections.deque([node])
        while queue:
            cur = queue.popleft()
            for neigh in cur.neighbors:
                if neigh.val not in all_nodes:
                    queue.append(neigh)
                    all_nodes[neigh.val] = Node(neigh.val)
                all_nodes[cur.val].neighbors.append(all_nodes[neigh.val])
        return all_nodes[node.val]
