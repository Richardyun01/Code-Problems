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
    ListNode* insertionSortList(ListNode* head) {
        // 선택 정렬 기법
        // ListNode 전체에서 순회
        for (auto i = head; i; i = i->next) {
            // i 이전까지 순회
            for (auto j = head; j != i; j = j->next) {
                // 이전 값이 더 크면 바꾸기
                if (j->val > i->val) {
                    swap(j->val, i->val);
                }
            }
        }
        return head;
    }
};