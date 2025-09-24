/*
  �˰��� �з�: ����, �ùķ��̼�

  ���� ��� �� ����
  - �ʱ�ȭ
    - ������ ũ�� N, ��� �� M, ���� �� �迭 A�� �Է�
    - �ʱ� ������ ��ġ�� (N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)
  - ��� ó��
    - �� ��ɿ� ���� ����� �Ÿ��� �Է¹޾� ������ �̵�
  - ���� �̵� �� �� ������
    - ������ �־��� ����� �Ÿ��� ���� �̵�
    - �̵��� ���� ��踦 �Ѿ�� �ݴ������� ����
    - �̵� �� ������ ��ġ�� ĭ�� �� ���� ���� ���� 1 ����
  - ��������� ����
    - �밢�� �������� ������ ĭ �� ���� �ִ� ĭ�� ����ŭ ���� ĭ�� ���� ����
  - ���� ����
    - ���� ���� 2 �̻��� ĭ�� ������ �����ϰ� ���� ���� 2 ����
    - ������ ������ �־��� ĭ�� ����
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