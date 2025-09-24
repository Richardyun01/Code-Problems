/*
  �˰��� �з�: �׷��� �̷�, �ִ� ���, ���ͽ�Ʈ��

  ���� ��� �� ����
  - �� ������ a, b, s�� ���� ��ǻ�� b���� a�� ���� ������ ����
  - ���ͽ�Ʈ�� �˰������� ��ŷ�� c���� �����ؼ� �� ��ǻ�ͱ��� �����Ǵ� �ּ� �ð��� ���
  - �켱 ���� ť�� ����� ��������� �ּ� ���� �ð��� �����ϰ� �� ª�� ��� �߰� �� ������Ʈ
  - ���� �ð��� INF�� �ƴ� ��ǻ���� ������ ���� �� ������ ��ǻ�� ���� ����
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