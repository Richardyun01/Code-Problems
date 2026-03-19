#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char grid[101][101];
// 방문 여부
bool vis[101][101];
int n;
// 방향
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void BFS(int a, int b) {
    queue<pair<int, int>> q;
    // 시작 좌표 방문 처리
    q.push({a, b});
    vis[a][b] = true;
    while (q.empty() == 0) {
        // 큐의 현재 위치
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 상하좌우 방향
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 다음 좌표가 그리드를 벗어나지 않았으면
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (vis[nx][ny] == false) {
                    // 인접한 좌표 색상이 동일하면 방문처리
                    if (grid[nx][ny] == grid[x][y]) {
                        vis[nx][ny] = true;
                        // 큐에 넣어 다음 탐색에 사용
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int ans1 = 0, ans2 = 0;
    // 일반인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == false) {
                BFS(i, j);
                ans1++;
            }
        }
    }
    // 메모리 초기화하고 G는 R로 처리
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'G') {
                grid[i][j] = 'R';
            }
        }
    }
    // 적록색맹
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == false) {
                BFS(i, j);
                ans2++;
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}