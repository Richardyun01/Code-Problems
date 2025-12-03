class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> check(26, false);
        // 각 알파벳이 등장한 횟수
        for (char c : s) {
            cnt[c - 'a']++;
        }
        // 문자열을 스택으로 사용
        string res;
        for (char c : s) {
            int idx = c - 'a';
            // 해당 문자 사용
            cnt[idx]--;
            // 결과에 이미 존재할 경우 스킵
            if (check[idx]) continue;
            // 마지막 문자가 현재 문자보다 크고 다시 나타날 경우: 순서를 맞추기 위해 팝
            while (!res.empty() && res.back() > c && cnt[res.back()-'a'] > 0) {
                check[res.back()-'a'] = false;
                res.pop_back();
            }
            // 해당 문자는 사용했다고 체크
            res.push_back(c);
            check[idx] = true;
        }
        return res;
    }
};