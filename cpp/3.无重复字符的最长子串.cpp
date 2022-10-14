/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int count(0);
        int r(0);
        for(int l=0;l<s.length();++l) {
            if(l > 0) {
                set.erase(s[l-1]);
            }
            while(r < s.length() && set.count(s[r]) == 0) {
                set.emplace(s[r]);
                r++;
            }
            count = max(count, r - l);
        }
        return count;
    }
};
// @lc code=end

