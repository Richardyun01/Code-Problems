/*
  알고리즘 분류: 구현, 브루트포스 알고리즘, 시뮬레이션, 백트래킹
  
  접근 방법 및 구현
  - office 배열에 사무실 상태 저장, cctvs에 CCTV의 위치와 종류를 저장
  - 각 CCTV 유형에 대한 모든 가능한 방향 조합을 정의
  - DFS 탐색으로 모든 CCTV 방향 조합을 탐색하여 각 경우마다 사각지대 계산
  - 특정 CCTV가 감시하는 영역을 tmp_office에 표시
  - 주의: DFS 함수에서 tmp_office의 배열 상태를 백업하고 복원해야 함(새로운 CCTV를 처리할 때 이전 CCTV들의 감시 영역도 유지되어야 함)
*/

#include <bits/stdc++.h>
using namespace std;
int MAX = 100000000;
int n, m;
int office[8][8];
int tmp_office[8][8];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pair<int, int>> grid;
vector<vector<vector<int>>> cctvs = {
    {{0}},                                        // 빈 공간
    {{0}, {1}, {2}, {3}},                         // 1
    {{0, 2}, {1, 3}},                             // 2
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},             // 3
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}}, // 4
    {{0, 1, 2, 3}}                                // 5
};
void copy_office(int src[8][8], int dest[8][8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dest[i][j] = src[i][j];
        }
    }
}
void mark(int x, int y, vector<int> directions) {
    for (int dir : directions) {
        int nx = x, ny = y;
        while (true) {
            nx += dx[dir];
            ny += dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || tmp_office[nx][ny] == 6)
                break;
            if (tmp_office[nx][ny] <= 0)
                tmp_office[nx][ny] = -1;
        }
    }
}
int calc_blind() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp_office[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
void dfs(int idx, int& min_blind) {
    if (idx == grid.size()) {
        min_blind = min(min_blind, calc_blind());
        return;
    }
    int x = grid[idx].first;
    int y = grid[idx].second;
    int type = office[x][y];
    int backup[8][8];
    for (auto dir : cctvs[type]) {
        copy_office(tmp_office, backup);
        mark(x, y, dir);
        dfs(idx+1, min_blind);
        copy_office(backup, tmp_office);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5)
                grid.push_back({i, j});
        }
    }
    copy_office(office, tmp_office);
    int min_blind = MAX;
    dfs(0, min_blind);
    cout << min_blind;
    return 0;
}