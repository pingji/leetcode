#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHeader = ListNode(0)
        cur = dummyHeader
        carry = 0
        while l1 != None or l2 != None:
            n1, n2= 0, 0
            if l1 != None:
                n1 = l1.val
                l1 = l1.next
            if l2 != None:
                n2 = l2.val
                l2 = l2.next
            sum = n1 + n2 + carry
            v = sum % 10
            carry = sum // 10
            cur.next = ListNode(v)
            cur = cur.next
        if carry > 0:
            cur.next = ListNode(carry)
            cur = cur.next
        return dummyHeader.next
# @lc code=end

