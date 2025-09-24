/*
  �˰��� �з�: �׷��� �̷�, �ִ� ���, ���ͽ�Ʈ��

  ���� ��� �� ����
  - �� �뼱 ������ �Է¹޾� graph ���Ϳ� ����
  - ���ͽ�Ʈ�� �˰���
    - �켱���� ť�� ����� ���� ���ÿ��� �� ���ñ����� �ּ� ��� ���
    - prev �迭�� �� ���÷� ���� ���� ���� ���� ����
  - ���� ���ÿ������� prev �迭�� ���� ��θ� �����ϰ� �������� ���� ����
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
    }
    int start, dest;
    cin >> start >> dest;
    const int INF = numeric_limits<int>::max();
    vector<int> dist(n+1, INF);
    vector<int> prev(n+1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cur_cost) continue;
        for (auto &edge : graph[cur]) {
            int next = edge.first;
            int cost = edge.second;
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                prev[next] = cur;
                pq.push({dist[next], next});
            }
        }
    }
    vector<int> path;
    for (int cur = dest; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    cout << dist[dest] << endl;
    cout << path.size() << endl;
    for (auto city : path) {
        cout << city << " ";
    }
    return 0;
}