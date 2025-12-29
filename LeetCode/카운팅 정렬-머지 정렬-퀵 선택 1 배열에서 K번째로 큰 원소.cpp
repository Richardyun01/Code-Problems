class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue로 인덱스 순서 자동 정렬
        priority_queue<int> pq(nums.begin(), nums.end());
        // 해당 값의 인덱스에 도달할 때까지 계속 pop
        for (int i = 0; i < k-1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};