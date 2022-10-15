/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int strLen = s.length();	
        int maxStart(0);
	    int maxEnd(0);
	    int maxLen(0);
        for(int i=0;i<strLen;++i) {
            int left(i-1);
            int right(i+1);
            int curLen(1);
            while (left >= 0 && s[left] == s[i]) {
                curLen++;
                left--;
            }
            while (right < strLen && s[right] == s[i]) {
                curLen++;
                right++;
            }
            while (left >= 0 && right < strLen && s[left] == s[right]) {
                curLen += 2;
                left--;
                right++;
            }
            if(curLen > maxLen) {
                maxLen = curLen;
                maxStart = left + 1;
                maxEnd = right - 1;
            }
        }
        return s.substr(maxStart, maxLen);
    }
};
// @lc code=end

