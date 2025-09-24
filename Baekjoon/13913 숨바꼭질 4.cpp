/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, �ʺ� �켱 Ž��

  ���� ��� �� ����
  - BFS: queue�� ����� ���� ��ġ���� ������ 3���� �̵��� �����Ͽ� �湮���� ���� ��ǥ�� ���
  - �θ� �迭: �� ��ǥ�� �����ϱ� ���� ������ ��ġ�ߴ� ��ǥ�� ����Ͽ� ���� ��θ� ����
  - ��� ����: parent �迭�� �Ųٷ� �����Ͽ� ��θ� path ���Ϳ� ���� �� reverse�� �����Ͽ� ���
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    const int MAX = 100000;
    vector<int> dist(MAX+1, -1);
    vector<int> parent(MAX+1, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == k) break;
        int next;
        next = cur - 1;
        if (next >= 0 && dist[next] == -1) {
            dist[next] = dist[cur] + 1;
            parent[next] = cur;
            q.push(next);
        }
        next = cur + 1;
        if (next <= MAX && dist[next] == -1) {
            dist[next] = dist[cur] + 1;
            parent[next] = cur;
            q.push(next);
        }
        next = cur * 2;
        if (next <= MAX && dist[next] == -1) {
            dist[next] = dist[cur] + 1;
            parent[next] = cur;
            q.push(next);
        }
    }
    cout << dist[k] << endl;
    vector<int> path;
    for (int cur = k; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    for (auto p : path) {
        cout << p << ' ';
    }
    return 0;
}