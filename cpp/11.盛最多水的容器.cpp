/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left(0);
        int right(height.size() - 1);
        int maxarea(0);
        int area(0);
        while(left < right) {
            if(height[left] > height[right]) {
                area = height[right] * (right - left);
                right--;
            } else {
                area = height[left] * (right - left);
                left++;
            }
            if(area > maxarea) {
                maxarea = area;
            }
        }
        return maxarea;
    }
};
// @lc code=end

