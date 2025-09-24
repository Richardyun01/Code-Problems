/*
  �˰��� �з�: �ڷ� ����, �׷��� �̷�, �켱���� ť, ���� ���ȯ �׷���, ���� ����

  ���� ��� �� ����
  - �� ���� ���ǿ� ���� �׷����� ���� �迭�� ����
  - �켱���� ť�� ����� ������ 0�� ������ �� ��ȣ�� ���� ������ ���� ����
  - ������ ������ ����� �� ����� �������� ������ ���ҽ�Ų �� 0�� �Ǹ� ť�� ����
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    vector<int> degree(N+1, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) pq.push(i);
    }
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        for (int next : graph[cur]) {
            degree[next]--;
            if (degree[next] == 0) pq.push(next);
        }
    }
    return 0;
}