class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                tmp++;
                if (i == nums.size()-1) {
                    if (tmp > ans) ans = tmp;
                }
            } else if (nums[i] == 0) {
                if (tmp > ans) ans = tmp;
                tmp = 0;
            }
        }
        return ans;
    }
};