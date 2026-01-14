class Solution {
public:
    string longestPrefix(string s) {
        int i = 0, j = -1;
        vector<int> fail(s.size()+1, 0);
        fail[0] = -1;
        while (i < s.size()) {
            if (j == -1 || s[i] == s[j]) {
                i++;
                j++;
                fail[i] = j;
            } else {
                j = fail[j];
            }
        }
        return s.substr(0, fail.back());
    }
};