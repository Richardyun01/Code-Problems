/*
  �˰��� �з�: ����, �ùķ��̼�

  �帧
  - �ʱ� ����: ������� ��ġ, ����, �ʱ� ��ġ �Է�
  - S�� ���� ���� �ݺ�
    - ����� �̵� �� ��� �̵� �� ���� ���� �� ����� ����
  - �ùķ��̼� ���� �� ���ڿ� ���� �ִ� ������� �� �� ��� �� ���

  ����
  - �̵� �˰���
    - �� ������ 8������ Ȯ���ϸ� �̵� ������ ĭ�� Ž��
    - �̵� �Ұ����ϸ� ���ڸ��� ����
  - ����� �̵� �ùķ��̼�
    - DFS�� ���� �� 3ĭ�� �̵��ϸ鼭 ����⸦ �ִ��� �Դ� ��� ź��
    - ���� ����� ���� �Դ� ��ΰ� �ټ��� ��� ���� ���� ���
  - ����
    - ����⸦ ���� ��ġ�� ������ 3�� ���� ����� �� �� ���� ����
  - ����� ����
    - �� ���� ���� ����� ���� �����ؼ� �� ���� �� �߰�

  ����
  - GRID_SIZE: ���� ũ��
  - dx, dy: ������� 8���� �̵� �迭
  - sx, sy: ����� 4���� �̵� ��
  - grid: ������ ����� ���� ���� 3���� ����, �� ĭ�� ����� ���� ��� ����
  - smell: ������ ���� �ð��� �����ϴ� 2���� ����
  - shark_x, shark_y: ����� ���� ��ġ
  - copy_fish(): �� ������ ����� ���� ����
  - move_fish()
    - ����� �̵� �Լ�
    - �� ����Ⱑ �ڽ� �������� 8�� ȸ���ؼ� �̵� ���� ĭ(���� ���� ��, ����/��� ����) �˻�
    - �̵� �Ұ� �� ���ڸ�
  - simulate_shark()
    - ����� ���� ��� Ž��
    - 3�� �̵� ���� �� �� �ܰ迡�� ����� ����
    - DFS ����ؼ� ������ ��� ��� Ž��
    - ���� ���: ���� ����� �� �ִ�, ���� ���� ��� �� ���� ���
  - move_shark()
    - �� ������ ��θ� ���� �̵�
    - �̵� �� ����⸦ �԰� ������ ����
  - decrease_smell()
    - ������ ��� ���� ���� �ð� 1 ����
  - replicate_fish()
    - ������ ����� ����� ���¸� ���� ���ڿ� �����Ͽ� ����
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