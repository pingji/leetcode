/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int p1 = 0; p1 < len - 3; p1++)
        {
            if (p1 > 0 && nums[p1] == nums[p1 - 1])
            {
                continue;
            }
            for (int p2 = p1 + 1; p2 < len - 2; p2++)
            {
                if (p2 > p1 + 1 && nums[p2] == nums[p2 - 1])
                {
                    continue;
                }

                int p3 = p2 + 1;
                int p4 = len - 1;
                while (p3 < p4)
                {
                    if (p3 > p2 + 1 && nums[p3] == nums[p3 - 1])
                    {
                        p3++;
                        continue;
                    }
                    if (p4 < len - 1 && nums[p4] == nums[p4 + 1])
                    {
                        p4--;
                        continue;
                    }
                    long long sum = 0LL + nums[p1] + nums[p2] + nums[p3] + nums[p4];
                    if (sum < target)
                    {
                        p3++;
                    }
                    else if (sum > target)
                    {
                        p4--;
                    }
                    else
                    {
                        ans.push_back({nums[p1], nums[p2], nums[p3], nums[p4]});
                        p3++;
                        p4--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
