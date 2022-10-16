/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    unordered_map<string, vector<string>> states = {
		{"start",    {"start", "signed", "in_number", "end"}},
		{"signed",    {"end", "end", "in_number", "end"}},
		{"in_number", {"end", "end", "in_number", "end"}},
		{"end",       {"end", "end", "end", "end"}},
	};
	int sign  = 1;
	long long ans   = 0;
	string state = "start";

    int getCol(char c) {
        if (c == ' ') {
            return 0;
        } else if (c == '+' || c == '-') {
            return 1;
        } else if (c >= '0' && c <= '9') {
            return 2;
        } else {
            return 3;
        }
    }

    void handleChar(char c) {
        int col = getCol(c);
        state = states[state][col];
        if (state == "signed") {
            if (c == '-') {
                sign = -1;
            }
        }
        if (state == "in_number") {
            ans = ans*10 + (c-'0');
            if(sign == 1) {
                ans = min(ans,  (1LL << 31) -1);
            } else {
                ans = min(ans,  1LL << 31);
            }
        }
    }


public:
    int myAtoi(string s) {
        for(int i=0;i<s.length();++i) {
            handleChar(s[i]);
            if(state == "end") {
                break;
            }
        }
        if(sign == 1) {
            return ans;
        } else {
            return -ans;
        }
    }
};
// @lc code=end

