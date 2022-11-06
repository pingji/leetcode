/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHeader = new ListNode();
        ListNode cur = dummyHeader;
        int carry = 0;

        while(l1 != null || l2 != null) {
            int n1 = 0;
            int n2 = 0;
            if(l1 != null) {
                n1 = l1.val;
                l1 = l1.next;
            }
            if(l2 != null) {
                n2 = l2.val;
                l2 = l2.next;
            }
            int sum = n1 + n2 + carry;
            int v = sum % 10;
            carry = sum / 10;
            cur.next = new ListNode(v);
            cur = cur.next;
        }
        if(carry > 0) {
            cur.next = new ListNode(carry);
            cur = cur.next;
        }

        return dummyHeader.next;
    }
}
// @lc code=end

