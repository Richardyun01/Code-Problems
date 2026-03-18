#include<iostream>
#include<deque>
using namespace std;
int grid[501][501];
// 방문 여부 표시
bool vis[501][501];
deque<pair<int, int>> q;
// 방향 설정
int dr[4] = {0, 0, 1, -1};
int dc[4] = {-1, 1, 0, 0};
int main() {
    // 초기 입력
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int num_pic = 0;
    int max_cnt = 0;
    // 그리드 전체에 대해서
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 아직 방문하지 않은 1을 찾은 경우
            if (grid[i][j] == 1 && !vis[i][j]) {
                // 시작점 정의: 시작 좌표를 큐에 넣고 그림 넓이를 1로 초기화
                q.push_back({i, j});
                vis[i][j] = 1;
                int cnt = 1;
                // BFS: 현재 위치를 꺼내서 연결된 1을 탐색
                while (q.size() != 0) {
                    auto [r, c] = q.front();
                    q.pop_front();
                    // 각 방향의 좌표로 이동하여
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        // 도화지를 벗어나는 경우 무시
                        if (nr < 0 || n <= nr || nc < 0 || m <= nc) {
                            continue;
                        }
                        // 인접한 좌표가 1이고 아직 방문하지 않으면 큐에 넣어 방문처리
                        if (grid[nr][nc] == 1 && !vis[nr][nc]) {
                            q.push_back({nr, nc});
                            vis[nr][nc] = 1;
                            cnt++;
                        }
                    }
                }
                max_cnt = max(max_cnt, cnt);
                num_pic++;
            }
        }
    }
    cout << num_pic << endl << max_cnt;
    return 0;
}