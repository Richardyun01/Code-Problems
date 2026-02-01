class Solution {
public:
    string ans = "";
    vector<char> alp = {'a', 'b', 'c'};
    string getHappyString(int n, int k) {
        backtrack(n, k, "");
        return ans;
    }
    int backtrack(int n, int k, string s) {
        if (s.size() == n) {
            k--;
            if (k == 0) {
                ans = s;
                return 0;
            }
            return k;
        } else {
            for (char c : alp) {
                if (s == "" || s[s.size()-1] != c) {
                    k = backtrack(n, k, s+c);
                    if (k == 0) {
                        return 0;
                    }
                }
            }
        }
        return k;
    }
};