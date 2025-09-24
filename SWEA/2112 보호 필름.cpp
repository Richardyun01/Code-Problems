/*
  접근 방법 및 구현
  - 모든 열이 동일한 특성을 가진 셀이 K개 이상 연속적으로 존재해야 함
  - 약물을 투여할 행을 선택할 때 순서는 결과에 영향을 미치지 않음 -> 조합 사용
  - 특정 막을 선택할 시 해당 막에 A와 B를 순서대로 넣음
  - 기존에 투여한 약물의 갯수보다 더 많으면 탐색 진행 X
  - 약물 투여 횟수가 K번 이상일 시 탐색 진행 X
*/

#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int D, W, K, res;
int map[21][21];
int c_map[21][21];
bool Select[21];
int compare_min(int a, int b) {
    if (a < b) return a;
    return b;
}
// 필름이 성능 검사를 통과하는지 확인인
bool check(int arr[][21]) {
    for (int i = 0; i < W; i++) {
        // 약품 A, B, 조건 만족
        int a_cnt = 0;
        int b_cnt = 0;
        bool flag = false;
        // 세로 방향 검사
        for (int j = 0; j < D; j++) {
            if (arr[j][i] == 0) {
                b_cnt = 0;
                a_cnt++;
            } else {
                a_cnt = 0;
                b_cnt++;
            }
            // 연속된 K개가 나오면 해당 열은 합격
            if (a_cnt == K || b_cnt == K) {
                flag = true;
                break;
            }
        }
        // 한 열이라도 실패할 시 불합격
        if (flag == false) return false;
    }
// cout << "Col pass" << endl;
    return true;
}
// 행 약품 처리 또는 상태 복구
void make_visit(int idx, int value, bool T) {
    // 약품 처리
    if (T == true) {
        for (int i = 0; i < W; i++) {
            c_map[idx][i] = value;
        }
// cout << "Row " << idx << " set to " << value << endl;
    // 복구
    } else {
        for (int i = 0; i < W; i++) {
            c_map[idx][i] = map[idx][i];
// cout << "Row " << idx << " restored" << endl;
        }
    }
}
void dfs(int idx, int cnt) {
    // 투입 횟수가 K보다 크거나 최소값 이상일 시 중단
    if (cnt > K || cnt >= res) return;
    // 검사 통과 시 최소값 갱신
    if (check(c_map) == true) {
        res = compare_min(res, cnt);
// cout << "Passed: " << res << " cnt: " << cnt << endl;
        return;
    }
    // 통과 못했을 시 다음 행에 약품 투입
    for (int i = idx; i < D; i++) {
        if (Select[i] == true) continue;
        Select[i] = true;
        // i번째 행에 A/B 투입
        for (int j = 0; j < 2; j++) {
            make_visit(i, j, true);
            dfs(i, cnt+1);
            make_visit(i, j, false);
        }
        // 백트래킹
        Select[i] = false;
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; ++tc)
	{
	    res = 999999999;
	    memset(Select, false, sizeof(Select));
        cin >> D >> W >> K;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
                c_map[i][j] = map[i][j];
            }
        }
        if (check(map) == true || K == 1) {
            res = 0;
        } else {
            dfs(0, 0);
        }
        cout << '#' << tc << ' ' << res << endl;
	}
	return 0;
}
?