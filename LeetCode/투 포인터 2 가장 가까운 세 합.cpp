class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size()-2; i++) {
            int l = i+1;
            int r = nums.size() - 1;
            while (l < r) {
                int tmp_sum = nums[l] + nums[r] + nums[i];
                if (abs(tmp_sum - target) < abs(closest - target)) {
                    closest = tmp_sum;
                }
                if (tmp_sum == target) {
                    return tmp_sum;
                } else if (tmp_sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return closest;
    }
};