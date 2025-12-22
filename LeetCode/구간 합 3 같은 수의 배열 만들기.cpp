class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        // suffix sum of all even/odd numbers
        vector<int> even(n+1);
        vector<int> odd(n+1);
        // calculate even/odd sum by step
        for (int i = n - 1; i >= 0; --i) {
            if (i % 2 == 0) even[i] += nums[i];
            else odd[i] += nums[i];
            even[i] += even[i+1];
            odd[i] += odd[i+1];
        }
        int even_sum = 0, odd_sum = 0, ans = 0;
        // find the same
        // check the eveness and add to the sum
        for (int i = 0; i < n; i++) {
            if (even_sum + odd[i+1] == odd_sum + even[i+1]) {
                ans++;
            }
            if (i % 2 == 0) even_sum += nums[i];
            else odd_sum += nums[i];
        }
        return ans;
    }
};