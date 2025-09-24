/*
  알고리즘 분류: 구현, 시뮬레이션

  접근 방법 및 구현
  - 초기화
    - 격자의 크기 N, 명령 수 M, 물의 양 배열 A를 입력
    - 초기 구름의 위치는 (N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)
  - 명령 처리
    - 각 명령에 대해 방향과 거리를 입력받아 구름을 이동
  - 구름 이동 및 비 내리기
    - 구름은 주어진 방향과 거리에 따라 이동
    - 이동은 격자 경계를 넘어가도 반대편으로 연결
    - 이동 후 구름이 위치한 칸에 비를 내려 물의 양을 1 증가
  - 물복사버그 마법
    - 대각선 방향으로 인접한 칸 중 물이 있는 칸의 수만큼 현재 칸의 물을 증가
  - 구름 생성
    - 물의 양이 2 이상인 칸에 구름을 생성하고 물의 양을 2 감소
    - 이전에 구름이 있었던 칸은 제외
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
int N, M;
int A[MAX][MAX];
int directions[8][2] = {{0, -1},
                        {-1, -1},
                        {-1, 0},
                        {-1, 1},
                        {0, 1},
                        {1, 1},
                        {1, 0},
                        {1, -1}};
bool visited[MAX][MAX];
vector<pair<int, int>> clouds;
void move_clouds(int d, int s) {
    vector<pair<int, int>> new_clouds;
    for (auto &cloud : clouds) {
        int r = cloud.first;
        int c = cloud.second;
        int nr = (r + directions[d][0] * s + N * s) % N;
        int nc = (c + directions[d][1] * s + N * s) % N;
        new_clouds.push_back({nr, nc});
    }
    clouds = new_clouds;
}
void rain() {
    memset(visited, false, sizeof(visited));
    for (auto &cloud : clouds) {
        int r = cloud.first;
        int c = cloud.second;
        A[r][c]++;
        visited[r][c] = true;
    }
}
void water_copy() {
    for (auto &cloud : clouds) {
        int r = cloud.first;
        int c = cloud.second;
        int water_count = 0;
        for (int i = 1; i < 8; i += 2) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && A[nr][nc] > 0) {
                water_count++;
            }
        }
        A[r][c]+= water_count;
    }
}
void generate_clouds() {
    vector<pair<int, int>> new_clouds;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] >= 2 && !visited[i][j]) {
                new_clouds.push_back({i, j});
                A[i][j] -= 2;
            }
        }
    }
    clouds = new_clouds;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    vector<pair<int, int>> moves(M);
    for (int i = 0; i < M; i++) {
        cin >> moves[i].first >> moves[i].second;
        moves[i].first--;
    }
    clouds = {{N-1, 0}, {N-1, 1}, {N-2, 0}, {N-2, 1}};
    for (int i = 0; i < M; i++) {
        int d = moves[i].first;
        int s = moves[i].second;
        move_clouds(d, s);
        rain();
        water_copy();
        generate_clouds();
    }
    int total_water = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total_water += A[i][j];
        }
    }
    cout << total_water << endl;
    return 0;
}