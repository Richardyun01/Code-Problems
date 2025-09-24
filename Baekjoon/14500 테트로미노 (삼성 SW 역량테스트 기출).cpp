/*
  알고리즘 분류: 구현, 브루트포스 알고리즘

  접근 방법 및 구현
  - 모든 회전 및 대칭된 테트로미노 모양을 좌표로 표현
  - 모든 시작 위치(i, j)에 대해 모든 테트로미노를 배치하며 가능한 최댓값 계산
  - 이때 테트로미노가 격자를 벗어나지 않도록 확인
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> tetromino = {
    // 직선
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    // 정사각형
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    // L
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    // L 뒤집음
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    // 번개
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
    // 번개 뒤집음
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    // T
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}}
};
int n, m;
vector<vector<int>> grid;
int calc() {
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (const auto& tetro : tetromino) {
                int cur_sum = 0;
                bool valid = true;
                for (const auto& block : tetro) {
                    int x = i + block.first;
                    int y = j + block.second;
                    if (x < 0 || x >= n || y < 0 || y >= m) {
                        valid = false;
                        break;
                    }
                    cur_sum += grid[x][y];
                }
                if (valid) {
                    max_sum = max(max_sum, cur_sum);
                }
            }
        }
    }
    return max_sum;
}
int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << calc();
    return 0;
}