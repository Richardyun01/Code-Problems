class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums);
        return nums;
    }

    void mergesort(vector<int>& nums) {
        if (nums.size() > 1) {
            int m = nums.size() / 2;
            vector<int> L;
            vector<int> R;
            for (int i = 0; i < m; i++) {
                L.push_back(nums[i]);
            }
            for (int i = m; i < nums.size(); i++) {
                R.push_back(nums[i]);
            }
            mergesort(L);
            mergesort(R);
            int i = 0, j = 0, k = 0;
            while (i < L.size() && j < R.size()) {
                if (L[i] < R[j]) {
                    nums[k] = L[i];
                    i++;
                } else {
                    nums[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < L.size()) {
                nums[k] = L[i];
                i++;
                k++;
            }
            while (j < R.size()) {
                nums[k] = R[j];
                j++;
                k++;
            }
        }
    }
};s\