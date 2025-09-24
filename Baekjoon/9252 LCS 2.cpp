/*
  알고리즘 분류: 다이나믹 프로그래밍, 문자열

  접근 방법 및 구현
  - dp 테이블 초기화: dp[i][j]는 s1의 처음 i글자와 s2의 처음 j글자 사이의 LCS 길이를 저장
  - DP 테이블 채우기
    - 두 문자열의 문자가 같으면 대각선 왼쪽 위의 값에 1을 더함
    - 두 문자열의 문자가 다르면 위쪽/왼쪽 값 중 큰 값으로 갱신
  - LCS 문자열 추적: DP 테이블을 뒤에서부터 추적하여 LCS 문자열을 구성한 후 문자열을 뒤집어 올바르게 출력
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << endl;
    if (dp[n][m] == 0) return 0;
    int i = n, j = m;
    string lcs;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        } else {
            if (dp[i-1][j] >= dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;
    return 0;
}