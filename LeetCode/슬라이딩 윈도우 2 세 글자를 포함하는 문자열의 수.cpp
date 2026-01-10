class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int l = 0;
        unordered_map<char, int> cnt= {{'a', 0}, {'b', 0}, {'c', 0}};
        for (int r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            while (cnt['a'] > 0 && cnt['b'] > 0 && cnt['c'] > 0) {
                ans += s.size() - r;
                cnt[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};