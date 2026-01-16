# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # list1이 비어있을 경우
        if list1 == None:
            return list2
        # list2가 비어있을 경우
        if list2 == None:
            return list1
        # list2의 값이 list1의 값 이상일 경우: list2를 list1 다음에 이어붙이기
        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        # 아니면 list1을 list2 다음에 이어붙이기
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2