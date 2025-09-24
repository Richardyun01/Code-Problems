/*
  �˰��� �з�: ���̳��� ���α׷���, Ʈ��, Ʈ�������� ���̳��� ���α׷���

  ���� ��� �� ����
  - ���� ��尡 ��� �����̸� ������ Ž���Ǵ� ������ ��� �Ϲ� �����̾�� ��
  - ���� ��尡 �Ϲ� �����̸� ������ Ž���Ǵ� ������ �Ϲ� ������ �� ����
  - dfs�� ���� dp�� �⺻�� ����
  - ���� Ʈ���� ���� ��� �������� �ִ��� dp[now][0]�� dp[now][1]�� ���� ��
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