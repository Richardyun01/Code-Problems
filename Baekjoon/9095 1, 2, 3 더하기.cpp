/*
  알고리즘 분류: 다이내믹 프로그래밍

  접근 방법 및 구현
  - 증가 추세: 1일 시 1, 2일 시 2, 3일 시 4, 4일 시 7, ...
  - 이를 반복하다 보면 n번째 수의 경우의 수는 n-1, n-2, n-3번째 수의 경우를 합친 것과 같음을 발견 가능
  - 따라서 점화식 dp[n] = dp[n-1]+dp[n-2]+dp[n-3] 획득
  - 점화식 내에서 모든 처리가 가능하므로 따로 수를 저장하고 처리할 필요가 없음
*/

#include<iostream>
#include<vector>
using namespace std;
int T, dp[1001];
int main() {
    cin >> T;
    // 점화식 개시
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    for (int i = 0; i < T; i++) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << endl;
    }
    return 0;
}