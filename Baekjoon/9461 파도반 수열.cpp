/*
  알고리즘 분류: 수학, 다이내믹 프로그래밍

  접근 방법 및 구현
  - dp 배열을 미리 정의, 값이 초과할 수 있으므로 long long으로 정의
  - 점화식: dp[i] = dp[i-2] + dp[i-3]
*/

#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;
		long long dp[101];
		dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2;
		for (int j = 4; j <= n; j++) {
			dp[j] = dp[j - 3] + dp[j - 2];
		}
		cout << dp[n] << endl;
	}
	return 0;
}