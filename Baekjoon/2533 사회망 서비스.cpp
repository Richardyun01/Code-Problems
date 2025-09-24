/*
  알고리즘 분류: 다이나믹 프로그래밍, 트리, 트리에서의 다이나믹 프로그래밍

  접근 방법 및 구현
    - 벡터를 통해 트리를 인접 리스트로 저장
    - DP 배열
    - dp[node][0]: 해당 노드가 얼리어댑터가 아닌 경우의 최소 수
    - dp[node][1]: 해당 노드가 얼리어댑터인 경우의 최소 수
    - DFS 탐색: 루트부터 DFS로 탐색해서 DP값 채움
    - 노드가 얼리어댑터가 아니면 자식 노드들은 모두 얼리어댑터야 함
    - 노드가 얼리어댑터면 자식 노드는 얼리어댑터일 수도 아닐 수도 있음
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000;
vector<int> tree[MAX_N+1];
int dp[MAX_N+1][2];
bool visited[MAX_N+1];
void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;
    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);
            dp[node][0] += dp[child][1];
            dp[node][1] += min(dp[child][0], dp[child][1]);
        }
    }
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}