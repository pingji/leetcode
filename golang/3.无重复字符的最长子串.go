/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	count := 0
	m := make(map[byte]int)

	r := 0
	for l := 0; l < len(s); l++ {
		if l > 0 {
			delete(m, s[l-1])
		}
		for r < len(s) && m[s[r]] == 0 {
			m[s[r]] = 1
			r++
		}
		count = max(count, r-l)
	}
	return count
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

// @lc code=end

