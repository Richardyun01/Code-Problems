class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> check(n, 0);
        for (int i : nums) {
            check[i-1] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (check[i] == 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};