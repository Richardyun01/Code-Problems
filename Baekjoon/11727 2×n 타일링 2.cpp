/*
  알고리즘 분류: 다이내믹 프로그래밍

  접근 방법 및 구현
  - dp를 저장하는 배열을 정의: 첫 3개의 값은 1, 3, 5 
  - n까지의 경우 = n-1까지의 모든 경우, n-2까지의 모든 경우 + 작은 타일 2개, n-2까지의 모든 경우 + 큰 타일 1개 -> 점화식: dp i-1 + 2 * dp i-2
  - 이때 매 반복마다 10007씩 나머지를 구해야 형을 초과하지 않음
*/

#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dp[1001];
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + 2*dp[i-2];
        dp[i] %= 10007;
    }
    cout << dp[n] % 10007;
    return 0;
}