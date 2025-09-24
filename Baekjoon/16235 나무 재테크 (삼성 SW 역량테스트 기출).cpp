/*
  �˰��� �з�: ����, �ڷᱸ��, �ùķ��̼�
  
  ���� ��� �� ����
  - ���� ����, ���� �� ���, �ܿ� �߰� ��� ����
  - ������ �˰��� ���� �� ���������� ó��
  - K���� ���� �� ��� �ִ� ������ ���� ���
*/

#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void spring(vector<vector<deque<int>>> &trees, vector<vector<int>> &nuts, vector<vector<int>> &dead_trees, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!trees[i][j].empty()) {
                sort(trees[i][j].begin(), trees[i][j].end());
                deque<int> new_trees;
                for (int age : trees[i][j]) {
                    if (nuts[i][j] >= age) {
                        nuts[i][j] -= age;
                        new_trees.push_back(age+1);
                    } else {
                        dead_trees[i][j] += age / 2;
                    }
                }
                trees[i][j] = new_trees;
            }
        }
    }
}
void summer(vector<vector<int>> &nuts, vector<vector<int>> &dead_trees, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            nuts[i][j] += dead_trees[i][j];
        }
    }
}
void fall(vector<vector<deque<int>>> &trees, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int age : trees[i][j]) {
                if (age % 5 == 0) {
                    for (int d = 0; d < 8; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                            trees[nx][ny].push_front(1);
                        }
                    }
                }
            }
        }
    }
}
void winter(vector<vector<int>> &nuts, const vector<vector<int>> &A, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            nuts[i][j] += A[i][j];
        }
    }
}
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> nuts(N, vector<int>(N, 5));
    vector<vector<deque<int>>> trees(N, vector<deque<int>>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x-1][y-1].push_back(z);
    }
    while (K--) {
        vector<vector<int>> dead_trees(N, vector<int>(N, 0));
        spring(trees, nuts, dead_trees, N);
        summer(nuts, dead_trees, N);
        fall(trees, N);
        winter(nuts, A, N);
    }
    int total_trees = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total_trees += trees[i][j].size();
        }
    }
    cout << total_trees;
    return 0;
}