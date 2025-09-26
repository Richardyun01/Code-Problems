/*
  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 격자 그래프, 플러드 필
  
  접근 방법 및 구현
  - BFS로 인접한 지점 탐색하는 문제
  - 방문하지 않은 점을 발견할 때마다 BFS로 연결된 칸들 전부 방문 표시하고 횟수 세기
  - 각 테스트 케이스마다 배열의 초기화 필요
*/

#include<iostream>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
int T, M, N, K;
int plant[51][51];
bool visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    visited[sy][sx] = true;
    q.push({sy, sx});
    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            // 채소밭 범위
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            // 배추가 있고 아직 방문하지 않으면 큐에 추가
            if (plant[ny][nx] == 1 && !visited[ny][nx]) {
// cout << "ny: " << ny << " nx: " << nx << endl;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
// cout << "ended" << endl;
}
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int res = 0;
        cin >> M >> N >> K;
        // tc마다 초기화
        for (int i = 0; i < N; i++) {
            fill(plant[i], plant[i]+M, 0);
            fill(visited[i], visited[i]+M, false);
        }
        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            plant[y][x] = 1;
        }
        // 새로운 연결요소 발견 시 BFS 실행
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (plant[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}