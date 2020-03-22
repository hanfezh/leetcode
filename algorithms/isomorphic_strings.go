// 205. Isomorphic Strings: https://leetcode.com/problems/isomorphic-strings
// Author: xianfeng.zhu@gmail.com
package main

import "fmt"

func isIsomorphic(s string, t string) bool {
	var letters [128]byte
	var mapped [128]bool
	for i, chr := range []byte(s) {
		if letters[chr] == 0 && !mapped[t[i]] {
			letters[chr] = t[i]
			mapped[t[i]] = true
		} else if letters[chr] == t[i] {
			continue
		} else {
			return false
		}
	}
	return true
}

func main() {
	s := "egg"
	t := "add"
	fmt.Printf("Input: s = \"%s\", t = \"%s\"\n", s, t)
	fmt.Printf("Output: %v\n", isIsomorphic(s, t))
}
