class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        deque<int> d;
        // (앞으로 더) 뽑아야 할 숫자의 개수
        // 현재까지 선택한 숫자의 리스트
        // 다음에 선택할 수 있는 최소 숫자가 주어짐
        backtrack(n, k, d, 1);
        return ans;
    }

    void backtrack(int n, int remain, deque<int>& c, int next) {
        // 종료 조건: 더 이상 뽑을 숫자가 없으면
        // 현재 조합 c를 복사해서 결과 리스트에 추가
        if (remain == 0) {
            ans.emplace_back(c.begin(), c.end());
            return;
        // 백트래킹
        // next부터 n까지 인덱스를 현재 조합에 추가
        // 뽑아야 할 숫자를 줄이고 재귀 호출
        // 재귀가 끝나면 마지막 숫자 제거(백트래킹)
        } else {
            for (int i = next; i <= n; i++) {
                c.push_back(i);
                backtrack(n, remain-1, c, i+1);
                c.pop_back();
            }
        }
    }
};