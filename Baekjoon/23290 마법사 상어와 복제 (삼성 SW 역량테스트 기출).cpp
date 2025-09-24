/*
  알고리즘 분류: 구현, 시뮬레이션

  흐름
  - 초기 설정: 물고기의 위치, 방향, 초기 위치 입력
  - S턴 동안 과정 반복
    - 물고기 이동 → 상어 이동 → 냄새 감소 → 물고기 복제
  - 시뮬레이션 종료 후 격자에 남아 있는 물고기의 총 수 계산 후 출력

  동작
  - 이동 알고리즘
    - 각 물고기는 8방향을 확인하며 이동 가능한 칸을 탐색
    - 이동 불가능하면 제자리에 남음
  - 상어의 이동 시뮬레이션
    - DFS를 통해 상어가 3칸을 이동하면서 물고기를 최대한 먹는 경로 탄색
    - 같은 물고기 수를 먹는 경로가 다수일 경우 사전 순서 고려
  - 냄새
    - 물고기를 먹은 위치에 냄새를 3턴 동안 남기고 매 턴 냄새 감소
  - 물고기 복제
    - 턴 시작 시의 물고기 상태 복제해서 턴 종료 후 추가

  구조
  - GRID_SIZE: 격자 크기
  - dx, dy: 물고기의 8방향 이동 배열
  - sx, sy: 상어의 4방향 이동 비열
  - grid: 격자의 물고기 상태 저장 3차원 벡터, 각 칸에 물고기 방향 목록 저장
  - smell: 냄새가 남은 시간을 저장하는 2차원 벡터
  - shark_x, shark_y: 상어의 현재 위치
  - copy_fish(): 두 격자의 물고기 상태 복사
  - move_fish()
    - 물고기 이동 함수
    - 각 물고기가 자신 기준으로 8번 회전해서 이동 가능 칸(격자 범위 내, 냄새/상어 없음) 검색
    - 이동 불가 시 제자리
  - simulate_shark()
    - 상어의 최적 경로 탐색
    - 3번 이동 수행 중 각 단계에서 물고기 먹음
    - DFS 사용해서 가능한 모든 경로 탐색
    - 최적 경로: 먹은 물고기 수 최대, 동일 수일 경우 더 작은 경로
  - move_shark()
    - 상어가 최적의 경로를 따라 이동
    - 이동 중 물고기를 먹고 냄새를 남김
  - decrease_smell()
    - 격자의 모든 냄새 지속 시간 1 감소
  - replicate_fish()
    - 이전에 백업한 물고기 상태를 현재 격자에 복제하여 번식
*/
#include <bits/stdc++.h>
using namespace std;
const int GRID_SIZE = 4;
const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int sx[4] = {-1, 0, 1, 0};
const int sy[4] = {0, -1, 0, 1};
vector<vector<vector<int>>> grid(GRID_SIZE, vector<vector<int>>(GRID_SIZE));
vector<vector<int>> smell(GRID_SIZE, vector<int>(GRID_SIZE, 0));
int shark_x, shark_y;
int M, S;
void copy_fish(vector<vector<vector<int>>> &source, vector<vector<vector<int>>> &target) {
    target = source;
}
void move_fish() {
    vector<vector<vector<int>>> new_grid(GRID_SIZE, vector<vector<int>>(GRID_SIZE));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            for (int d : grid[i][j]) {
                int new_dir = d;
                bool moved = false;
                for (int k = 0; k < 8; k++) {
                    int cur_dir = (d-k+8) % 8;
                    int nx = i + dx[cur_dir];
                    int ny = j + dy[cur_dir];
                    if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE &&
                        smell[nx][ny] == 0 && !(nx == shark_x && ny == shark_y)) {
                        new_grid[nx][ny].push_back(cur_dir);
                        moved = true;
                        break;
                    }
                }
                if (!moved) {
                    new_grid[i][j].push_back(d);
                }
            }
        }
    }
    copy_fish(new_grid, grid);
}
tuple<int, vector<int>> simulate_shark(int x, int y, vector<int> path, int depth, int eaten, vector<vector<vector<int>>> &tmp_grid) {
    if (depth == 3) return {eaten, path};
    tuple<int, vector<int>> best = {-1, {}};
    for (int i = 0; i < 4; i++) {
        int nx = x + sx[i];
        int ny = y + sy[i];
        if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
            path.push_back(i);
            int local_eaten = tmp_grid[nx][ny].size();
            vector<int> backup_fish = tmp_grid[nx][ny];
            tmp_grid[nx][ny].clear();
            auto [next_eaten, next_path] = simulate_shark(nx, ny, path, depth+1, eaten+local_eaten, tmp_grid);
            if (next_eaten > get<0>(best) || 
                (next_eaten == get<0>(best) && next_path < get<1>(best))) {
                best = {next_eaten, next_path};
            }
            tmp_grid[nx][ny] = backup_fish;
            path.pop_back();
        }
    }
    return best;
}
void move_shark() {
    vector<vector<vector<int>>> tmp_grid = grid;
    auto [_, best_path] = simulate_shark(shark_x, shark_y, {}, 0, 0, tmp_grid);
    for (int i : best_path) {
        shark_x += sx[i];
        shark_y += sy[i];
        if (!grid[shark_x][shark_y].empty()) {
            smell[shark_x][shark_y] = 3;
            grid[shark_x][shark_y].clear();
        }
    }
}
void decrease_smell() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (smell[i][j] > 0) smell[i][j]--;
        }
    }
}
void replicate_fish(vector<vector<vector<int>>> &backup) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j].insert(grid[i][j].end(), backup[i][j].begin(), backup[i][j].end());
        }
    }
}
int main() {
    cin >> M >> S;
    for (int i = 0; i < M; i++) {
        int fx, fy, d;
        cin >> fx >> fy >> d;
        fx--; fy--; d--;
        grid[fx][fy].push_back(d);
    }
    cin >> shark_x >> shark_y;
    shark_x--; shark_y--;
    for (int i = 0; i < S; i++) {
        vector<vector<vector<int>>> backup = grid;
        move_fish();
        move_shark();
        decrease_smell();
        replicate_fish(backup);
    }
    int result = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            result += grid[i][j].size();
        }
    } 
    cout << result << endl;
    return 0;
}