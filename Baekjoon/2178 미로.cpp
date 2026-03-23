#include<iostream>
#include<deque>
using namespace std;
int n, m;
char grid[101][101];
// 시작점으로부터의 거리
int check[101][101];
// 방문 여부
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int a, int b) {
    // 해당 지점에서부터 시작
    vis[a][b] = true;
    deque<pair<int, int>> q;
    q.push_back({a, b});
    while (!q.empty()) {
        // 큐 맨 앞의 위치에 대해
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        // 전 방향에서
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 이동한 위치가 맵 내고 조건 만족 시
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (grid[nx][ny] == '1' && vis[nx][ny] == false) {
                    // 해당 지점의 진행도를 1 올리고 방문 처리, 큐에 넣음
                    check[nx][ny] = check[x][y] + 1;
                    vis[nx][ny] = true;
                    q.push_back({nx, ny});
                }
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    bfs(0, 0);
    cout << check[n-1][m-1]+1;
    return 0;
}