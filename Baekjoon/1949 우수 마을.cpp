/*
  알고리즘 분류: 다이나믹 프로그래밍, 트리, 트리에서의 다이나믹 프로그래밍

  접근 방법 및 구현
  - 현재 노드가 우수 마을이면 다음에 탐색되는 마을은 모두 일반 마을이어야 함
  - 현재 노드가 일반 마을이면 다음에 탐색되는 마을은 일반 마을일 수 있음
  - dfs를 통해 dp의 기본값 세팅
  - 서브 트리에 속한 우수 마을들의 최댓값이 dp[now][0]과 dp[now][1]에 들어가야 함
*/

#include <bits/stdc++.h>
using namespace std;
int N;
int dp[10001][2];
int civil_num[10001];
bool visited[10001];
vector<int> tree[10001];
void dfs(int now) {
    visited[now] = true;
    dp[now][0] = 0;
    dp[now][1] = civil_num[now];
    for (int i = 0; i < tree[now].size(); i++) {
        int next = tree[now][i];
        if (visited[next]) continue;
        dfs(next);
        dp[now][0] += max(dp[next][0], dp[next][1]);
        dp[now][1] += dp[next][0];
    }
}
int main() {
    int u, v;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> civil_num[i];
    }
    for (int i = 1; i < N; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}