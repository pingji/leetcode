/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start

#include "shared.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto cur = head;
        while(cur != nullptr && cur->next != nullptr) {
            if(cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

