/*
  �˰��� �з�: ���̳��� ���α׷���, Ʈ��, Ʈ�������� ���̳��� ���α׷���

  ���� ��� �� ����
    - ���͸� ���� Ʈ���� ���� ����Ʈ�� ����
    - DP �迭
    - dp[node][0]: �ش� ��尡 �󸮾���Ͱ� �ƴ� ����� �ּ� ��
    - dp[node][1]: �ش� ��尡 �󸮾������ ����� �ּ� ��
    - DFS Ž��: ��Ʈ���� DFS�� Ž���ؼ� DP�� ä��
    - ��尡 �󸮾���Ͱ� �ƴϸ� �ڽ� ������ ��� �󸮾���;� ��
    - ��尡 �󸮾���͸� �ڽ� ���� �󸮾������ ���� �ƴ� ���� ����
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