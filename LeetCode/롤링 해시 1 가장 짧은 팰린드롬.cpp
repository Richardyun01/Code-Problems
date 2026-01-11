class Solution {
public:
    string shortestPalindrome(string s) {
        // 팰린드롬을 떼어내기 위한 임시 문장
        string tmp = s;
        // 가장 긴 부분 팰린드롬 반환
        string longest_prefix = KMPSearch(s);
        // 접두사 부분 팰린드롬 때어내고 나머지만 남기기
        size_t pos = tmp.find(longest_prefix);
        if (pos != string::npos) {
            tmp.erase(pos, longest_prefix.length());
        }
        // 나머지를 뒤집고 원본의 앞에다 붙이기
        reverse(tmp.begin(), tmp.end());
        s = tmp + s;
        return s;
    }

    // 가장 긴 부분 팰린드롬 탐색
    // KMP 알고리즘 이용
    string KMPSearch(string s) {
        // 임시 문자열 생성(중앙 경계선으로 '?' 붙이기)
        string tmp = s + "?";
        // 기존 문자열 뒤집기
        reverse(s.begin(), s.end());
        // 임시 문자열과 기존 문자열 합치기 -> 이러면 원본 문자열 - ? - 뒤집힌 문자열 완성
        tmp = tmp + s;
        // 전체 문자열 길이
        int n = tmp.size();
        // 가장 긴 팰린드롬 길이를 저장할 해시맵 생성
        vector<int> lps(n, 0);
        // 문자열 순회
        for (int i = 1; i < n; i++) {
            // 인덱스까지의 가장 긴 접두사의 길이
            int prefix_len = lps[i-1];
            // 인덱스+1의 길이 계산
            while (prefix_len > 0 && tmp[prefix_len] != tmp[i]) {
                prefix_len = lps[prefix_len-1];
            }
            // 현재 인덱스의 문자와 접두사 길이에서의 문자와 동일할 시 다음 문자로 
            if (tmp[i] == tmp[prefix_len]) {
                prefix_len++;
            }
            // 팰린드롬 길이 해시맵 값 정의
            lps[i] = prefix_len;
        }
        // 가장 긴 팰린드롬을 반환
        string longest = "";
        for (int i = 0; i < lps[n-1]; i++) {
            longest += tmp[i];
        }
        // cout << longest;
        return longest;
    }
};