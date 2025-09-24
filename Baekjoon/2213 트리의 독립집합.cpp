/*
  알고리즘 분류: 다이나믹 프로그래밍, 트리, 트리에서의 다이나믹 프로그래밍

  접근 방법 및 구현
  - 트리 입력: 가중치를 입력받고 간선 정보로 트리 구성
  - DFS와 DP를 이용한 최대 독립 집합 계산
    - dp[node][0]: 현재 노드를 포함하지 않는 최대 독립 집합 크기
    - dp[node][1]: 현재 노드를 포함하는 최대 독립 집합 크기
    - selected[node][0]: 노드를 포함하지 않을 때 선택된 정점들
    - selected[node][1]: 노드를 포함할 때 선택된 정점들
  - 최대 독립 집합 크기 결정
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10000;
vector<int> tree[MAX_N+1];
int weight[MAX_N+1];
bool visited[MAX_N+1];
int dp[MAX_N+1][2];
vector<int> selected[MAX_N+1][2];
void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = weight[node];
    for (int child : tree[node]) {
        if (visited[child]) continue;
        dfs(child);
        dp[node][0] += max(dp[child][0], dp[child][1]);
        if (dp[child][0] > dp[child][1]) {
            selected[node][0].insert(selected[node][0].end(), selected[child][0].begin(), selected[child][0].end());
        } else {
            selected[node][0].insert(selected[node][0].end(), selected[child][1].begin(), selected[child][1].end());
        }
        dp[node][1] += dp[child][0];
        selected[node][1].insert(selected[node][1].end(), selected[child][0].begin(), selected[child][0].end());
    }
    selected[node][1].push_back(node);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    int res = max(dp[1][0], dp[1][1]);
    vector<int> nodes;
    if (dp[1][0] > dp[1][1]) nodes = selected[1][0];
    else nodes = selected[1][1];
    sort(nodes.begin(), nodes.end());
    cout << res << endl;
    for (int node : nodes) {
        cout << node << ' ';
    }
    return 0;
}