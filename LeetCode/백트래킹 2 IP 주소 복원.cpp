// DFS 방식의 백트래킹
class Solution {
public:
    // 유효한 IP 주소'들'을 담음
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        // 아예 불가능한 경우
        if (s.size() > 12 || s.size() < 4) {
            return ans;
        }
        // 임시로 빈 배열 정의해서 넣기
        vector<string> tmp;
        backtrack(0, tmp, s);
        return ans;
    }
    void backtrack(int start, vector<string> seg, string s) {
        // 각 블럭 4개가 완성됨
        if (seg.size() == 4) {
            if (start == s.size()) {
                // 모든 숫자를 사용했을 경우
                // 유효한 IP 주소이므로 블럭들을 .으로 연결하고 저장
                string tmp = "";
                for (int i = 0; i < seg.size(); i++) {
                    tmp += seg[i];
                    if (i != seg.size()-1) {
                        tmp += ".";
                    }
                }
                ans.push_back(tmp);
            } else {
                // 유효하지 않은 IP 주소
                return;
            }
        } else {
            // 문자열의 현재 시작 인덱스에서 끝까지
            // 시작 인덱스는 블럭마다 지속적으로 갱신됨
            for (int end = start+1; end <= s.size(); end++) {
                // 현재 블럭을 숫자로 변환
                int num = stoi(s.substr(start, end - start));
                // 현재 블럭의 길이가 0이고 그 값이 10 미만인 경우:
                // 앞이 0인 두 자리 수 -> 프루닝함
                if (end - start == 2 && num < 10) {
                    return;
                }
                // 블럭 값이 255보다 클 경우:
                // 더 커지는 것을 피하기 위해 루프 종료
                if (num > 255) {
                    break;
                }
                // 재귀로 반복
                // 현재 인덱스가 새로운 블럭의 새로운 인덱스가 됨
                // 이전의 블럭들은 담겨 있는 상태
                seg.push_back(to_string(num));
                backtrack(end, seg, s);
                seg.pop_back();
            }
        }
    }
};