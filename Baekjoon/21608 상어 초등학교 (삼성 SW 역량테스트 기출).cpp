/*
  �˰��� �з�: ����, �ڷᱸ��, �ùķ��̼�
  
  ���� ��� �� ����
  - �Է� �ʱ�ȭ
    - N -> ���� ũ�� ����, �л��� ���� ����
    - ����: N x N 2���� ���ͷ� �ʱ�ȭ
  - �л� �ڸ� ��ġ
    - �� �л����� �� �ڸ� �߿��� ���ǿ� ���� ������ ��ġ�� �˻�
    - �� �ڸ� �ĺ��� ������ ĭ�� �����ϴ� �л� ��/�� ĭ ��/��� �� ������ ����
    - ���� ������ �ڸ��� �л��� ��ġ
  - K���� ���� �� ��� �ִ� ������ ���� ���
    - �л��� ���� �ڸ����� ������ ĭ�� �����ϴ� �л� ���� ���� �������� ���
    - �� �������� ��ȯ
*/
#include <bits/stdc++.h>
using namespace std;
struct Student {
    int id;
    vector<int> favorites;
};
struct Cell {
    int row, col;
    int favorite_cnt, empty_cnt;
};
int N;
vector<vector<int>> classroom;
vector<Student> students;
vector<int> score = {0, 1, 10, 100, 1000};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool is_valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}
void place_student(const Student &student) {
    vector<Cell> candidates;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (classroom[r][c] == 0) {
                int favorite_cnt = 0, empty_cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (is_valid(nr, nc)) {
                        if (classroom[nr][nc] == 0) {
                            empty_cnt++;
                        } else if (find(student.favorites.begin(), student.favorites.end(), classroom[nr][nc]) != student.favorites.end()) {
                            favorite_cnt++;
                        }
                    }
                }
                candidates.push_back({r, c, favorite_cnt, empty_cnt});
            }
        }
    }
    sort(candidates.begin(), candidates.end(), [](const Cell &a, const Cell &b) {
        if (a.favorite_cnt != b.favorite_cnt) return a.favorite_cnt > b.favorite_cnt;
        if (a.empty_cnt != b.empty_cnt) return a.empty_cnt > b.empty_cnt;
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col;
    });
    classroom[candidates[0].row][candidates[0].col] = student.id;
}
int calc_satisfaction() {
    int total_satisfaction = 0;
    for (const auto &student : students) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (classroom[r][c] == student.id) {
                    int favorite_cnt = 0;
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (is_valid(nr, nc) && find(student.favorites.begin(), student.favorites.end(), classroom[nr][nc]) != student.favorites.end()) {
                            favorite_cnt++;
                        }
                    }
                    total_satisfaction += score[favorite_cnt];
                    break;
                }
            }
        }
    }
    return total_satisfaction;
}
int main() {
    cin >> N;
    classroom.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N*N; i++) {
        Student student;
        cin >> student.id;
        student.favorites.resize(4);
        for (int j = 0; j < 4; j++) {
            cin >> student.favorites[j];
        }
        students.push_back(student);
    }
    for (const auto &student : students) {
        place_student(student);
    }
    cout << calc_satisfaction() << endl;
    return 0;
}