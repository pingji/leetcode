/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int p1=0;p1<len-2;p1++) {
            if(p1 > 0 && nums[p1] == nums[p1-1]) {
                continue;
            }
            if(nums[p1] > 0) {
                break;
            }
            int p2=p1+1;
            int p3=len-1;
            while(p2 < p3) {
                if(p2 > p1 +1 && nums[p2] == nums[p2-1]) {
                    p2++;
                    continue;
                }
                if(p3<len-1 && nums[p3] == nums[p3+1]) {
                    p3--;
                    continue;
                }
                int sum = nums[p1] + nums[p2] + nums[p3];
                if(sum < 0) {
                    p2++;
                } else if(sum > 0) {
                    p3--;
                } else {
                    ans.push_back({nums[p1], nums[p2], nums[p3]});
                    p2++;
                    p3--;
                }
            }

        }
        return ans;
    }
};
// @lc code=end

