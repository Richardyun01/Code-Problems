class Solution {
public:
    int magicalString(int n) {
        string magic = "";
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                magic += "2";
                if (magic[i-1] == '1') {
                    continue;
                } else if (magic[i-1] == '2') {
                    magic += "2";
                }
            } else if (i % 2 == 1) {
                magic += "1";
                if (magic[i-1] == '1') {
                    continue;
                } else if (magic[i-1] == '2') {
                    magic += "1";
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (magic[i] == '1') {
                ans++;
            }
        }
        return ans;
    }
};