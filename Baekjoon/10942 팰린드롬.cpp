/*
  알고리즘 분류: 다이나믹 프로그래밍

  접근 방법 및 구현
  - 초기화
    - dp[i][i] = 1 (길이 1인 부분 수열은 항상 팰린드롬)
    - dp[i][i+1] = 1 (두 개의 연속된 값이 같으면 팰린드롬)
  - DP 테이블 채우기
    - dp[start][end]를 채울 때 dp[start+1][end-1]이 true고 arr[start] == arr[end]이면 dp[start][end] = true
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000;
int arr[MAX_N+1];
bool dp[MAX_N+1][MAX_N+1];
int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i][i] = true;
    }
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i+1]) dp[i][i+1] = true;
    }
    for (int len = 3; len <= N; len++) {
        for (int start = 1; start <= N-len+1; start++) {
            int end = start+len-1;
            if (arr[start] == arr[end] && dp[start+1][end-1]) {
                dp[start][end] = true;
            }
        }
    }
    cin >> M;
    while (M--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }
    return 0;
}