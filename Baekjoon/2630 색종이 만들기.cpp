/*
  알고리즘 분류: 분할 정복, 재귀

  접근 방법 및 구현
  - 주어진 사각형을 N/2로 나눠가면서 탐색을 진행해야 함
  - 맵을 점점 줄여나가면서 하얀색 또는 파랑색으로만 이루어져 있는지를 파악하면 됨
  - 만약 단일 색상이 아닐 경우 더 작은 사각형으로 나누어야 함
  - 그러므로 절반으로 나눌 때의 모든 경우의 횟수(4번)만큼 재귀를 수행해야 함
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
    // 4개의 영역(길이/크기 절반씩)에 대해 진행
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