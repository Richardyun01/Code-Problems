/*
  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 격자 그래프

  접근 방법 및 구현
  - BFS로 구현해야 하므로 토마토밭, 방문 여부, xy 방향, 임시 큐를 정의
  - 우선 방문 여부 배열을 -1로 초기화한 다음 시작 부분만 0으로 설정, BFS에서 방문 가능한 점이면 +1
  - BFS 처리 후 방문 여부에 따라 일수 증가, 방문하지 않은 장소 = 방문 불가 장소가 있다면 -1을 출력
*/

#include<iostream>
#include<queue>
#define endl '\n';
using namespace std;
int M, N, res = -1;
int tomato[1001][1001];
// 방문 여부
int visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs() {
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            // 점 이동
            int na = a + dx[i];
            int nb = b + dy[i];
            // 해당 점이 방문하지 않은 이동 가능한 점일 시: 큐로 push하고 방문 처리
            if (na >= 0 && nb >= 0 && N > na && M > nb && visited[na][nb] == -1 && tomato[na][nb] == 0) {
// cout << "na: " << na << " nb: " << nb << endl;
                q.push(make_pair(na, nb));
                visited[na][nb] = visited[a][b] + 1;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
// cout << tomato[i][j] << ' ';
            // 아직 방문 안함
            visited[i][j] = -1;
            // 시작점
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j]++;
            }
// cout << visited[i][j] << ' ';
        }
// cout << endl;
    }
    bfs();
    bool check = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
// cout << visited[i][j] << ' ';
            // 진행할 때마다 res 값 증가
            if (res <= visited[i][j]) {
                res = visited[i][j];
            }
            // 토마토가 없는데 방문 못했을 경우 = 접근 불가능할 경우
            if (tomato[i][j] == 0 && visited[i][j] == -1) {
                res = -1;
                check = true;
                break;
            }
        }
// cout << endl;
        if (check) {
            break;
        }
    }
    cout << res << endl;
    return 0;
}