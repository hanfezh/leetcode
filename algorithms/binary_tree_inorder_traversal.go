package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	var nodes []*TreeNode
	var values []int

	for root != nil || len(nodes) > 0 {
		for root != nil {
			// Push root
			nodes = append(nodes, root)
			root = root.Left
		}

		// Pop root
		root = nodes[(len(nodes) - 1)]
		nodes = nodes[:(len(nodes) - 1)]

		// Visit root
		values = append(values, root.Val)
		root = root.Right
	}

	return values
}

func main() {
	node1 := TreeNode{1, nil, nil}
	node2 := TreeNode{5, nil, nil}
	root := TreeNode{3, &node1, &node2}
	values := inorderTraversal(&root)
	for i := range values {
		fmt.Println(values[i])
	}
}
