class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table{{0, -1}};
        int mod = 0;
        for (int i = 0; i < nums.size(); i++) {
            mod = (mod + nums[i]) % k;
            if (!table.contains(mod)) {
                table[mod] = i;
            } else if (i - table[mod] > 1) {
                return true;
            }
        }
        return false;
    }
};