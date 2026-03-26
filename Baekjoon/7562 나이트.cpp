#include<iostream>
#include<queue>
using namespace std;
int grid[301][301];
bool vis[301][301];
queue<pair<int, int>> q;
int startX, startY, endX, endY;
int len;
// 나이트 이동 8방향
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// 그리드 및 큐 초기화
void reset() {
    while (!q.empty()) {
        q.pop();
    }
    for (int i = 0; i < 301; i++) {
        for (int j = 0; j < 301; j++) {
            grid[i][j] = 0;
            vis[i][j] = false;
        }
    }
}
void bfs(int x, int y) {
    q.push({x, y});
    vis[x][y] = true;
    while (!q.empty()) {
        // 현재 위치를 구하기
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        // 현재 위치가 최종 위치와 동일하면 출력하고 종료
        if (r == endX && c == endY) {
            cout << grid[r][c] << endl;
            while (!q.empty()) {
                q.pop();
            }
            break;
        }
        // 나이트가 이동 가능한 8방향에 대해서
        for (int i = 0; i < 8; i++) {
            // 나이트 이동
            int dr = r + dx[i];
            int dc = c + dy[i];
            // 이동한 위치가 그리드 내에 있고 방문하지 않았다면 그곳으로 이동하고 위치를 저장 
            if (0 <= dr && dr < len && 0 <= dc && dc < len && !vis[dr][dc]) {
                q.push({dr, dc});
                vis[dr][dc] = true;
                grid[dr][dc] = grid[r][c] + 1;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> len;
        cin >> startX >> startY >> endX >> endY;
        bfs(startX, startY);
        reset();
    }
    return 0;
}