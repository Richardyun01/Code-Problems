/*
  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프

  접근 방법 및 구현
  - 목표 지점을 pair를 사용해 위치를 저장
  - 방문 처리를 위해서 좌표당 거리를 저장하는 배열을 -1로 초기화 -> 도달 불가능 위치를 의미
  - 시간복잡도를 줄이기 위해 목표 지점에서 모든 좌표를 방문: 개별에서 시작하면 n^2를 n^2번 해야하기 때문
  - 목표 지점=시작 위치: 0으로 표시
*/

#include<iostream>
#include<queue>
#define endl '\n'
using namespace std;
int N, M;
int map[1002][1002];
int dist[1002][1002];
pair<int, int> goal;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
void bfs() {
    // 시작점: 목표 지점
    queue<pair<int, int>> q;
    q.push(goal);
    // 목표 지점의 값 0
    dist[goal.first][goal.second] = 0;
    while (!q.empty()) {
        // 현재 위치
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            // 이동할 위치
            pair<int, int> next = {
                cur.first+dy[i], cur.second+dx[i]
            };
// cout << cur.first+dy[i] << ' ' << cur.second+dx[i] << endl;
            // 지도 밖일 경우 스킵
            if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) {
// cout << "out" << endl;
                continue;
            }
            // 이미 지나가거나 벽이면 스킵
            if (dist[next.first][next.second] != -1) {
// cout << "passed/wall" << endl;
                continue;
            }
            // 다음 위치/목표 지점까지 거리 저장
            q.push(next);
            dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
// cout << dist[cur.first][cur.second] << ' ' << dist[next.first][next.second] << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&dist[0][0], &dist[1001][1001], -1);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                goal.first = i;
                goal.second = j;
            }
            // 벽일 시 
            if (map[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}