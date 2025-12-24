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
// 내림차순으로 정렬되는 단조 스택 사용
// 현재 노드의 값이 스택의 다른 노드들보다 더 크면 스택 내 모든 노드들에 대해 next_larger(stk_node) = new_node가 성립함
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* cur = head;
        vector<int> input;
        while (cur) {
            input.push_back(cur->val);
            cur = cur->next;
        }
        int n = input.size();
        stack<int> stk;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            // input[i] 이하의 모든 stk 원소를 pop하고 ans의 값을 각각에 대해 정의
            while (!stk.empty() && input[i] > input[stk.top()]) {
                ans[stk.top()] = input[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};