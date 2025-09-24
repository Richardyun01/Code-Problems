/*
  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색

  접근 방법 및 구현
  - BFS: queue를 사용해 현재 위치에서 가능한 3가지 이동을 진행하여 방문하지 않은 좌표를 기록
  - 부모 배열: 각 좌표에 도달하기 위해 이전에 위치했던 좌표를 기록하여 최종 경로를 복원
  - 경로 복원: parent 배열을 거꾸로 추적하여 경로를 path 벡터에 저장 후 reverse로 정렬하여 출력
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