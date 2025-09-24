/*
  알고리즘 분류: 그래프 이론, 최단경로, 플로이드-워셜

  접근 방법 및 구현
  - V(정점)과 E(간선)을 입력받고 2차원 벡터 dist를 INF로 초기화
  - 자기 자신으로 가는 거리(dist[i][i])를 0으로 설정
  - 간선 정보 입력
  - 플로이드-워셜 알고리즘으로 모든 정점 간 최단거리 계산
  - i -> j -> i로 돌아오는 최소 거리 검색
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> dist(V+1, vector<int>(V+1, INF));
    for (int i = 1; i <= V; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    int min_cycle = INF;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i != j && dist[i][j] != INF && dist[j][i] != INF) {
                min_cycle = min(min_cycle, dist[i][j]+dist[j][i]);
            }
        }
    }
    if (min_cycle == INF) cout << -1 << endl;
    else cout << min_cycle << endl;
    return 0;
}