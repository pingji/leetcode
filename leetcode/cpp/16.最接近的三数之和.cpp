/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = nums[0] + nums[1] + nums[2];
        int len = nums.size();
        for(int p1=0;p1<len-2;p1++) {
            int p2=p1+1;
            int p3=len-1;
            while(p2 < p3) {
                int sum = nums[p1] + nums[p2] + nums[p3];
                if(abs(sum - target) < abs(best - target)) {
                    best = sum;
                }
                if(sum < target) {
                    p2++;
                } else if(sum > target) {
                    p3--;
                } else {
                    return target;
                }
            }

        }
        return best;
    }
};
// @lc code=end
