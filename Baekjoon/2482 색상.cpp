/*
  알고리즘 분류: 다이나믹 프로그래밍

  접근 방법 및 구현
  - 동적 계획법 배열 초기화
    - dp[i][j]: i개의 색상환에서 j개의 색을 선택하는 경우의 수
    - 0개 선택하는 경우는 1가지
    - 1개 선택하는 경우는 i가지
  - 점화식 적용
    - dp[i-2][j-1]: j-1개를 선택했을 때 현재 색을 포함하는 경우
    - dp[i-1][j]: 현재 색을 선택하지 않고 넘어가는 경우
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000003;
int main() {
    int N, K;
    cin >> N >> K;
    if (K > N / 2) {
        cout << 0;
        return 0;
    }
    int dp[1001][1001] = {0,};
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }
    cout << (dp[N-1][K]+dp[N-3][K-1]) % MOD;
    return 0;
}
