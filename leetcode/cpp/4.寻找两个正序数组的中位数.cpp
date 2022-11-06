/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len % 2 == 1) {
            return findKthElement(nums1, 0, len1-1, nums2, 0, len2-1, len/2 + 1 ) / 1.0;
        } else {
            return (findKthElement(nums1, 0, len1-1, nums2, 0, len2-1, len/2 ) +
                    findKthElement(nums1, 0, len1-1, nums2, 0, len2-1, len/2 + 1 )) / 2.0;
        }
    }

    int findKthElement(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1;
        if(len1 <= 0) {
            return nums2[start2 + k -1];
        }
        int len2 = end2 - start2 + 1;
        if(len2 <= 0) {
            return nums1[start1 + k -1];
        }
        if(k==1) {
            return min(nums1[start1], nums2[start2]);
        }
        int index1 = min(end1, start1 + k/2 -1);
        int index2 = min(end2, start2 + k/2 -1);
        if(nums1[index1] <= nums2[index2]) {
            k = k - (index1 - start1 + 1);
            return findKthElement(nums1, index1 + 1, end1, nums2, start2, end2, k);
        } else {
            k = k - (index2 - start2 + 1);
            return findKthElement(nums1, start1, end1, nums2, index2 + 1, end2, k);
        }
    }
};
// @lc code=end

