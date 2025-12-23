class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int min_val = 1e9;
        for (int i = 0; i < arr.size()-1; i++) {
            if (abs(arr[i] - arr[i+1]) < min_val) {
                min_val = abs(arr[i] - arr[i+1]);
            }
        }
        for (int i = 0; i < arr.size()-1; i++) {
            vector<int> tmp;
            if (abs(arr[i] - arr[i+1]) == min_val) {
                tmp.push_back(arr[i]);
                tmp.push_back(arr[i+1]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};