/*
  알고리즘 분류: 자료 구조, 그래프 이론, 우선순위 큐, 방향 비순환 그래프, 위상 정렬

  접근 방법 및 구현
  - 각 제약 조건에 따라 그래프와 제약 배열을 구성
  - 우선순위 큐를 사용해 제약이 0인 문제들 중 번호가 작은 문제를 먼저 선택
  - 선택한 문제를 출력한 후 연결된 문제들의 제약을 감소시킨 뒤 0이 되면 큐에 넣음
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