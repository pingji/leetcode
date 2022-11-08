/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.size() == 0)
        {
            return res;
        }

        sort(intervals.begin(), intervals.end(), [&](const auto &x, const auto &y) -> bool
             { return x[0] <= y[0]; });

        auto cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= cur[1])
            {
                cur[1] = max(cur[1], intervals[i][1]);
            }
            else
            {
                res.push_back(cur);
                cur = intervals[i];
            }
        }
        res.push_back(cur);
        return res;
    }
};
// @lc code=end
