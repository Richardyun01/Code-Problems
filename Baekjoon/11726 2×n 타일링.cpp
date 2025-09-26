/*
  알고리즘 분류: 다이나믹 프로그래밍

  접근 방법 및 구현
  - 2*1 크기 직사각형 = 1가지
  - 2*2 크기 직사각형 = 2가지
  - 2*3 크기 직사각형 = 3가지, 2*4 크기 직사각형 = 5가지, ...
  - 위의 패턴을 통해 점화식 dp[i] = dp[i-1] + dp[i-2]를 유추해낼 수 있음
*/

#include<iostream>
#define endl '\n'
using namespace std;
int N, dp[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        // 점화식
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] = dp[i] % 10007;
    }
    cout << dp[N] << endl;
    return 0;
}