/*
  알고리즘 분류: 구현, 그래프 이론, 그래프 탐색, 시뮬레이션, 너비 우선 탐색
  
  접근 방법 및 구현
  - 입력 초기화
    - N -> 격자 크기
    - M -> 색상 갯수
  - 반복
    - 격자의 모든 칸을 순회하여 일반 블록이고 아직 방문하지 않은 칸에서 BFS를 수행해 조건 만족하는 그룹을 저장
    - 찾은 모든 그룹을 정렬하여 가장 적합한 그룹 선택
    - 블록 그룹 제거 및 점수 계산
    - 중력 적용
    - 격자 회전
    - 중력 재적용
  - 블록 그룹이 더 없을 시 반복 종료
*/
#include <bits/stdc++.h>
using namespace std;
struct Group {
    int size;
    int rainbow_cnt;
    int standard_row;
    int standard_col;
    vector<pair<int, int>> blocks;
};
int N, M;
int grid[20][20];
bool visited[20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool compare_groups(const Group &a, const Group &b) {
    if (a.size != b.size) return a.size > b.size;
    if (a.rainbow_cnt != b.rainbow_cnt) return a.rainbow_cnt > b.rainbow_cnt;
    if (a.standard_row != b.standard_row) return a.standard_row > b.standard_row;
    return a.standard_col > b.standard_col;
}
Group find_group(int start_x, int start_y, int color) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> blocks;
    bool rainbow_visited[20][20] = {false};
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    blocks.push_back({start_x, start_y});
    int rainbow_cnt = 0;
    int standard_row = start_x;
    int standard_col = start_y;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny] || grid[nx][ny] == -1) continue;
            if (grid[nx][ny] == 0 && !rainbow_visited[nx][ny]) {
                rainbow_visited[nx][ny] = true;
                q.push({nx, ny});
                blocks.push_back({nx, ny});
                rainbow_cnt++; 
            } else if (grid[nx][ny] == color) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                blocks.push_back({nx, ny});
                if (nx < standard_row || (nx == standard_row && ny < standard_col)) {
                    standard_row = nx;
                    standard_col = ny;
                }
            }
        }
    }
    for (auto &[x, y] : blocks) {
        if (grid[x][y] == 0) visited[x][y] = false;
    }
    return {static_cast<int>(blocks.size()), rainbow_cnt, standard_row, standard_col, blocks};
}
void apply_gravity() {
    for (int c = 0; c < N; c++) {
        for (int r = N-2; r >= 0; r--) {
            if (grid[r][c] >= 0) {
                int current_row = r;
                while (current_row+1 < N && grid[current_row+1][c] == -2) {
                    grid[current_row+1][c] = grid[current_row][c];
                    grid[current_row][c] = -2;
                    current_row++;
                }
            }
        }
    }
}
void rotate_grid() {
    int tmp[20][20];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tmp[N - j - 1][i] = grid[i][j];
        }
    }
    memcpy(grid, tmp, sizeof(tmp));
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    int score = 0;
    while (true) {
        memset(visited, false, sizeof(visited));
        vector<Group> groups;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    Group group = find_group(i, j, grid[i][j]);
                    if (group.size >= 2) groups.push_back(group);
                }
            }
        }
        if (groups.empty()) break;
        sort(groups.begin(), groups.end(), compare_groups);
        Group best_group = groups[0];
        for (auto &[x, y] : best_group.blocks) {
            grid[x][y] = -2;
        }
        score += best_group.size * best_group.size;
        apply_gravity();
        rotate_grid();
        apply_gravity();
    }
    cout << score << endl;
    return 0;
}