/*
  �˰��� �з�: �׷��� �̷�, �ִܰ��, �÷��̵�-����

  ���� ��� �� ����
  - V(����)�� E(����)�� �Է¹ް� 2���� ���� dist�� INF�� �ʱ�ȭ
  - �ڱ� �ڽ����� ���� �Ÿ�(dist[i][i])�� 0���� ����
  - ���� ���� �Է�
  - �÷��̵�-���� �˰������� ��� ���� �� �ִܰŸ� ���
  - i -> j -> i�� ���ƿ��� �ּ� �Ÿ� �˻�
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