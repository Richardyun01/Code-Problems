class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, up = 0;
        for (int i = 1; i < nums.size(); i++) {
            // 현재 층이 이전 층과 값이 다를 경우 작업의 수를 그만큼 증가
            if (nums[i] != nums[i-1]) {
                up++;
            }
            ans += up;
        }
        return ans;
    }
};