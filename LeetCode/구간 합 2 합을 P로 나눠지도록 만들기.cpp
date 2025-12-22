class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long init_sum = 0;
        int n = nums.size();
        for (int i : nums) {
            init_sum += i;
        }
        int ans = 0;
        int target = init_sum % p;
        if (!target) {
            return 0;
        } 
        unordered_map<int, int> mod;
        mod[0] = -1;
        int cur = 0, min_len = n;
        for (int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p;
            int need = (cur - target + p) % p;
            if (mod.find(need) != mod.end()) {
                min_len = min(min_len, i - mod[need]);
            }
            mod[cur] = i;
        }
        if (min_len == n) {
            min_len = -1;
        }
        return min_len;
    }
};