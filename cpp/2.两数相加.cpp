/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHeader = new ListNode(0);
        ListNode* cur = dummyHeader;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr) {
            int n1 = 0;
            int n2 = 0;
            if(l1 != nullptr) {
                n1 = l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                n2 = l2->val;
                l2 = l2->next;
            }
            int sum = n1 + n2 + carry;
            int v = sum % 10;
            carry = sum / 10;
            cur->next = new ListNode(v);
            cur = cur->next;
        }
        if(carry > 0) {
            cur->next = new ListNode(carry);
            cur = cur->next;
        }

        return dummyHeader->next;
    }
};
// @lc code=end

