/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 */

// @lc code=start
package main

func longestPalindrome(s string) string {
	strLen := len(s)
	maxStart := 0
	maxEnd := 0
	maxLen := 0

	for i := 0; i < strLen; i++ {
		left := i - 1
		right := i + 1
		curLen := 1
		for left >= 0 && s[left] == s[i] {
			curLen += 1
			left--
		}
		for right < strLen && s[right] == s[i] {
			curLen += 1
			right++
		}
		for left >= 0 && right < strLen && s[left] == s[right] {
			curLen += 2
			left--
			right++
		}
		if curLen > maxLen {
			maxLen = curLen
			maxStart = left + 1
			maxEnd = right - 1
		}
	}
	return s[maxStart : maxEnd+1]
}

// @lc code=end
