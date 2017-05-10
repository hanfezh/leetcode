#! /usr/bin/env python
# encoding: utf8

# Path Sum 2
# Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

__author__ = "ufengzhu<xianfeng.zhu@gmail.com>"

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    def addChild(self, x):
        prev = None
        node = self
        while node is not None:
            prev = node
            if node.val > x:
                if node.left is None:
                    node.left = TreeNode(x)
                    break
                node = node.left
            else:
                if node.right is None:
                    node.right = TreeNode(x)
                    break
                node = node.right

    def traverse(self):
        nodes = [self]

        while len(nodes) > 0:
            n = nodes.pop(0)
            left = n.left
            right = n.right
            if n.left is not None:
                nodes.append(n.left)
            if n.right is not None:
                nodes.append(n.right)
            print "%d" % (n.val)



class Solution(object):
    def __pathSum(self, root, sum, llist, ilist):
        if not root:
            return

        sum -= root.val
        if sum == 0 and not root.left and not root.right:
            nlist = list(ilist)
            nlist.append(root.val)
            llist.append(nlist)
        if root.left:
            ilist.append(root.val)
            self.__pathSum(root.left, sum, llist, ilist)
            del ilist[len(ilist) - 1:]
        if root.right:
            ilist.append(root.val)
            self.__pathSum(root.right, sum, llist, ilist)
            del ilist[len(ilist) - 1:]

    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        llist = []
        self.__pathSum(root, sum, llist, [])
        return llist


def main():
    root = TreeNode(10)
    root.addChild(5)
    root.addChild(3)
    root.addChild(6)
    root.addChild(15)
    root.addChild(13)
    root.addChild(18)
    root.traverse()
    sol = Solution()
    print sol.pathSum(root, 18)

if __name__ == "__main__":
    main()
