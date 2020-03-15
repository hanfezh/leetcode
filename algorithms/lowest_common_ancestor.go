// 236. Lowest Common Ancestor of a Binary Tree
// Author: xianfeng.zhu@gmail.com
package main

import "fmt"

// Definition for TreeNode.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	node := root
	for node != nil {
		parentVal := node.Val
		if p.Val > parentVal && q.Val > parentVal {
			node = node.Right
		} else if p.Val < parentVal && q.Val < parentVal {
			node = node.Left
		} else {
			return node
		}
	}
	return nil
}

func main() {
	root := TreeNode{0, nil, nil}
	p := TreeNode{2, nil, nil}
	q := TreeNode{3, nil, nil}
	node := lowestCommonAncestor(&root, &p, &q)
	fmt.Printf("Output: %v\n", node)
}
