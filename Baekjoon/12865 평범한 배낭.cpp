/*
  알고리즘 분류: 다이나믹 프로그래밍, 배낭 문제

  접근 방법 및 구현
  - 0/1 배낭 문제
  - dp[i][j]는 첫 i개의 아이템을 고려할 때 배낭의 용량이 j일 때 얻을 수 있는 최대 가치를 저장
  - i번째 아이템을 선택하는 경우와 선택할 수 없는 경우를 모두 고려하여 점화식 작성
  - 현재 용량 j가 아이템의 무게보다 크거나 같을 때만 해당 아이템 선택 가능 -> 더 큰 값을 저장
*/

#include <bits/stdc++.h>
using namespace std;
pair<int, int> object[101];
int dp[101][100001];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> object[i].first >> object[i].second;
    }
    for (int i = 1; i <= n; i++) {
        int weight = object[i-1].first;
        int value = object[i-1].second;
        for (int j = 0; j <= k; j++) {
            if (j >= weight) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
    return 0;
}