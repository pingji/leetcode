/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
    unordered_map<char, int> m = {
        {'I', 1},
	    {'V', 5},
	    {'X', 10},
	    {'L', 50},
	    {'C', 100},
	    {'D', 500},
	    {'M', 1000},
    };
public:
    int romanToInt(string s) {
        int sum(0);
        int len = s.length();
        for(int i=0;i<len;++i) {
            if(i<len-1 &&  m[s[i]] <  m[s[i+1]]) {
                sum -= m[s[i]];
            } else {
                sum += m[s[i]];
            }
        }
        return sum;
    }
};
// @lc code=end

