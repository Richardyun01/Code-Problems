# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        cur = head;
        input = []
        while cur:
            input.append(cur.val)
            cur = cur.next
        n = len(input)
        stk = []
        ans = [0] * n
        for i in range(0, n):
            while stk and input[i] > input[stk[-1]]:
                ans[stk[-1]] = input[i]
                stk.pop()
            stk.append(i)
        return ans