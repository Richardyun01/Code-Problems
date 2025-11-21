/*
  알고리즘 분류: 다이내믹 프로그래밍

  접근 방법 및 구현
  - dp를 저장하는 배열을 정의: 첫 3개의 값은 계단 1, 계단 1+2, 계단 1+3과 계단 2+3 중 최댓값
  - 점화식: dp i-2+계단 i와 dp i-3+계단 i-1+계단 i 중 최댓값
*/

#include<iostream>
using namespace std;
int Max(int a, int b) {
    if (a > b) return a;
    return b;
}
int main() {
    int n;
    int stairs[301];
    int dp[301];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }
    dp[1] = stairs[1];
    dp[2] = stairs[1]+stairs[2];
    dp[3] = Max(stairs[1]+stairs[3], stairs[2]+stairs[3]);
    for (int i = 4; i <= n; i++) {
        dp[i] = Max(dp[i-2]+stairs[i], dp[i-3]+stairs[i-1]+stairs[i]);
    }
    cout << dp[n] << endl;
    return 0;
}