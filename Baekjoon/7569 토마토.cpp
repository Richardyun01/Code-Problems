#include<iostream>
#include<queue>
using namespace std;
int n, m, h;
int box[101][101][101];
int vis[101][101][101];
// 6개 방향 설정(3차원)
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
queue<pair<pair<int, int>, int>> q;
void bfs() {
    while (!q.empty()) {
        // 현재 토마토의 좌표 꺼내기
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < m && 0 <= nz && nz < n) {
                // 인접한 위치에 안 익은 토마토가 있으면 익는데 걸린 일수를 계산하고 새로 익은 토마토를 큐에 넣음
                if (box[nx][ny][nz] == 0) {
                    box[nx][ny][nz] = box[x][y][z] + 1;
                    q.push({{nx, ny}, nz});
                }
            }
        }
    }
}
int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                cin >> box[i][j][k];
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (box[i][j][k] == 1) {
                    q.push({{i, j}, k});
                }
            }
        }
    }
    int ans = 0;
    bfs();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                // 안익은 토마토가 남아있을 시 모두 익지 못함
                if (box[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                // 모두 익었으면 가장 큰 값을 탐색
                } else {
                    if (box[i][j][k] > ans) {
                        ans = box[i][j][k];
                    }
                }
            }
        }
    }
    cout << ans - 1;
    return 0;
}