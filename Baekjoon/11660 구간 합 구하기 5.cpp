/*
  알고리즘 분류: 다이나믹 프로그래밍, 누적 합

  접근 방법 및 구현
  - 그냥 그리드 합으로 접근 시 시간 초과가 발생하므로 DP를 이용해야 함
  - 2차원 DP 배역을 정의하고 매 타일마다 누적합을 저장
  - 구간 합을 구할 시 전체 영역인 x2, y2에서 시작 지점 영역들을 빼고 중복해서 빼진 영역을 더하면 됨
*/

#include<iostream>
#define endl '\n'
using namespace std;
int N, M;
int map[1025][1025];
int dp[1025][1025];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int x1, y1, x2, y2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            // 누적합: 중복해서 더해지는 dp[i-1][j-1]를 빼줘야 함
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1] + map[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        // 구간 합: 전체 영역 - 논외 지역 + 중복 해서 빼진 값
        sum = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << sum << endl;
    }
    return 0;
}
?