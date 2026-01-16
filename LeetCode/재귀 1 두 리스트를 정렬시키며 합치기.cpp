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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 둘 중 하나가 빌 때까지 재귀를 반복
        // list1이 비어있을 때
        if (list1 == NULL) {
            return list2;
        }
        // list2가 비어있을 때
        if (list2 == NULL) {
            return list1;
        }
        // list1의 값이 list2의 값보다 크거나 같을 경우
        // list1의 다음을 list2에 연결
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        // 아니면 list2의 다음을 list1에 연결
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};