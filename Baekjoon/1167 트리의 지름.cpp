/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, Ʈ��, ���� �켱 Ž��

  ���� ��� �� ����
  - ���� ��忡�� ���� �� ��带 �˻�
  - ù DFS���� ã�� ���� �� ��忡�� �ٽ� ���� �� ��带 �˻�
    - �̶��� �Ÿ��� Ʈ���� ������ ��
*/

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int idx;
    int dist;
};
int v, max_dist, max_node;
bool visited[100001];
vector<Node> tree[100001];
void dfs(int node, int dist) {
    if (visited[node]) return;
    if (max_dist < dist) {
        max_dist = dist;
        max_node = node;
    }
    visited[node] = true;
    for (int i = 0; i < tree[node].size(); i++) {
        int next_idx = tree[node][i].idx;
        int next_dist = tree[node][i].dist;
        dfs(next_idx, next_dist+dist);
    }
}
int main() {
    cin >> v;
    int from, to, dist;
    for (int i = 0; i < v; i++) {
        cin >> from;
        while (1) {
            cin >> to;
            if (to == -1) break;
            cin >> dist;
            tree[from].push_back({to, dist});
            tree[to].push_back({from, dist});
        }
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    max_dist = 0;
    dfs(max_node, 0);
    cout << max_dist;
    return 0;
}