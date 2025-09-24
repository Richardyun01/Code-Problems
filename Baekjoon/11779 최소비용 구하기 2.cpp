/*
  알고리즘 분류: 그래프 이론, 최단 경로, 다익스트라

  접근 방법 및 구현
  - 각 노선 정보를 입력받아 graph 벡터에 저장
  - 다익스트라 알고리즘
    - 우선순위 큐를 사용해 시작 도시에서 각 도시까지의 최소 비용 계산
    - prev 배열로 각 도시로 오기 전의 도시 정보 저장
  - 도착 도시에서부터 prev 배열을 통해 경로를 복원하고 역순으로 순서 나열
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