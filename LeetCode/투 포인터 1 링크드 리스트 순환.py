# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        # 현재 노드와 다음 노드가 존재할 때
        while fast and fast.next:
            head = head.next
            fast = fast.next.next
            if head == fast:
                return True
        return False