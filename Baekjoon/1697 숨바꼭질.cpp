/*
  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색

  접근 방법 및 구현
  - 각 경우에 대해서 탐색을 해야 하므로 BFS를 이용해야 함
  - 동생을 찾지 못했을 시 x+1, x-1, x*2를 각각 visit에 넣어 방문했는지 검사
  - 방문하지 않았다면 각각을 큐에 넣으면 됨
  - 현재 큐의 first가 동생의 위치와 동일할 시 정답
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
bool visit[100001];
// 경로 복원용
int parent[100001];
// 현재 위치, 걸린 시간: 가중치가 모두 1일 때 최단 거리 보장
queue<pair<int, int>> q;

void bfs(int n) {
    visit[n] = true;
    // 시작점
    parent[n] = -1;
    q.push({n, 0});
    while (!q.empty()) {
        int x   = q.front().first;
        int cnt = q.front().second;
        q.pop();
        // 목표 지점에 도착하면 더 이상 탐색할 필요 없음
        if (x == K) {
            cout << cnt << '\n';
// // 경로 복원
// vector<int> path;
// for (int v = K; v != -1; v = parent[v]) {
//     path.push_back(v);
// }
// reverse(path.begin(), path.end());
// for (size_t i = 0; i < path.size(); ++i) {
//     cout << path[i] << (i + 1 < path.size() ? ' ' : '\n');
// }
            return;
        }
        int next;
        // x+1
        next = x+1;
        if (0 <= next && next <= 100000 && !visit[next]) {
            visit[next] = true;
            parent[next] = x;
            q.push({next, cnt + 1});
// cout << "x+1: " << next << " " << cnt+1 << endl;
        }
        // x-1
        next = x-1;
        if (0 <= next && next <= 100000 && !visit[next]) {
            visit[next] = true;
            parent[next] = x;
            q.push({next, cnt+1});
// cout << "x-1: " << next << " " << cnt+1 << endl;
        }
        // x*2
        next = x*2;
        if (0 <= next && next <= 100000 && !visit[next]) {
            visit[next] = true;
            parent[next] = x;
            q.push({next, cnt+1});
// cout << "x*2: " << next << " " << cnt+1 << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    fill(visit, visit+100001, false);
    fill(parent, parent+100001, -1);
    bfs(N);
    return 0;
}