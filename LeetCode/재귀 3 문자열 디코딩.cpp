class Solution {
public:
    string decodeString(string s) {
        // 시작 위치
        int pos = 0;
        return helper(pos, s);
    }

    string helper(int& pos, string s) {
        // 각 단어 블록의 반복해야 하는 횟수
        int num = 0;
        // 전체 문자열
        string word = "";
        for (; pos < s.size(); pos++) {
            char cur = s[pos];
            // 현재 기호가 '['인 경우
            // 새로운 단어 구성을 탐색 시작해서 단어를 새로 완성
            // 해당 단어를 num만큼 전체 문장에 합치기
            if (cur == '[') {
                string cur_str = helper(++pos, s);
                for (; num > 0; num--) {
                    word += cur_str;
                }
            // 현재 기호가 숫자인 경우
            // 해당 블록의 전체 수를 구성
            } else if (cur >= '0' && cur <= '9') {
                num = num*10 + (cur - '0');
            // 현재 기호가 ']'인 경우
            // 새로운 단어를 완성하고 반환
            } else if (cur == ']') {
                return word;
            // 현재 기호가 문자인 경우
            // 새로운 단어를 계속 구성해나감
            } else {
                word += cur;
            }
        }
        return word;
    }
};