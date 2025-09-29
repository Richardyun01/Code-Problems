/*
  �˰��� �з�: ���� ����, ���

  ���� ��� �� ����
  - �־��� �簢���� N/2�� �������鼭 Ž���� �����ؾ� ��
  - ���� ���� �ٿ������鼭 �Ͼ�� �Ǵ� �Ķ������θ� �̷���� �ִ����� �ľ��ϸ� ��
  - ���� ���� ������ �ƴ� ��� �� ���� �簢������ ������� ��
  - �׷��Ƿ� �������� ���� ���� ��� ����� Ƚ��(4��)��ŭ ��͸� �����ؾ� ��
*/

#include<iostream>
using namespace std;
int N, blue, white;
int grid[129][129];
void dfs(int x, int y, int size) {
    bool zero = true, one = true;
    for (int i = x; i < x+size; i++) {
        for (int j = y; j < y+size; j++) {
            if (grid[i][j] == 1) zero = false;
            if (grid[i][j] == 0) one = false;
        }
    }
    if (zero == true) {
        white++;
        return;
    } else if (one == true) {
        blue++;
        return;
    }
    // 4���� ����(����/ũ�� ���ݾ�)�� ���� ����
    dfs(x, y, size/2);
    dfs(x, y+size/2, size/2);
    dfs(x+size/2, y, size/2);
    dfs(x+size/2, y+size/2, size/2);
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    dfs(0, 0, N);
    cout << white << endl << blue << endl;
    return 0;
}