/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "shared.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummyHead = new ListNode(0, head);
        auto prev = dummyHead;
        auto tail = dummyHead;
        for(int i=0; i<n; ++i) {
            tail = tail->next;
        }
        while(tail->next != nullptr) {
            prev = prev->next;
            tail = tail->next;
        }
        prev->next = prev->next->next;
        return dummyHead->next;
    }
};
// @lc code=end

