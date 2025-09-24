/*
  알고리즘 분류: 그래프 이론, 최단 경로, 다익스트라

  접근 방법 및 구현
  - 각 의존성 a, b, s에 대해 컴퓨터 b에서 a로 가는 간선을 구성
  - 다익스트라 알고리즘으로 해킹된 c에서 시작해서 각 컴퓨터까지 감염되는 최소 시간을 계산
  - 우선 순위 큐를 사용해 현재까지의 최소 감염 시간을 관리하고 더 짧은 경로 발견 시 업데이트
  - 감염 시간이 INF가 아닌 컴퓨터의 개수를 세어 총 감염된 컴퓨터 수를 구함
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, d, c;
        cin >> n >> d >> c;
        vector<vector<pair<int, int>>> graph(n+1);
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }
        const int INF = 1e9;
        vector<int> dist(n+1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[c] = 0;
        pq.push({0, c});
        while (!pq.empty()) {
            auto [time, cur] = pq.top();
            pq.pop();
            if (time > dist[cur]) continue;
            for (auto &edge : graph[cur]) {
                int next = edge.first;
                int w = edge.second;
                if (dist[next] > time+w) {
                    dist[next] = time+w;
                    pq.push({dist[next], next});
                }
            }
        }
        int cnt = 0, max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF) {
                cnt++;
                max_time = max(max_time, dist[i]);
            }
        }
        cout << cnt << ' ' << max_time << '\n';
    }
    return 0;
}