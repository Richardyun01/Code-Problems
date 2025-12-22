class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> als;
        als.push_back(0);
        int n = 0;
        for (int i : gain) {
            n = n + i;
            als.push_back(n);
        }
        sort(als.begin(), als.end());
        // for (int i : als) {
        //     cout << i << " ";
        // }
        return als[als.size()-1];
    }
};