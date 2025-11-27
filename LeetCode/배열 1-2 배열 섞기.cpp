class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> tmp1;
        vector<int> tmp2;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            tmp1.push_back(nums[i]);
        }
        for (int i = n; i < 2*n; i++) {
            tmp2.push_back(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(tmp1[i]);
            ans.push_back(tmp2[i]);
        }
        return ans;
    }
};