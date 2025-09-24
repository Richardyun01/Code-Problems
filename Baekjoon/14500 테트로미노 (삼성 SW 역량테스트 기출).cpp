/*
  �˰��� �з�: ����, ���Ʈ���� �˰���

  ���� ��� �� ����
  - ��� ȸ�� �� ��Ī�� ��Ʈ�ι̳� ����� ��ǥ�� ǥ��
  - ��� ���� ��ġ(i, j)�� ���� ��� ��Ʈ�ι̳븦 ��ġ�ϸ� ������ �ִ� ���
  - �̶� ��Ʈ�ι̳밡 ���ڸ� ����� �ʵ��� Ȯ��
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> tetromino = {
    // ����
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    // ���簢��
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    // L
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    // L ������
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    // ����
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
    // ���� ������
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