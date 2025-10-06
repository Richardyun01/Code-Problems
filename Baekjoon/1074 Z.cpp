/*
  알고리즘 분류: 분할 정복, 재귀

  - 접근 방법 및 구현
  - 현재 탐색하고자 하는 사분면의 가장 왼쪽 위 좌표를 입력받는 함수 정의
  - 찾고자 하는 좌표값이 현재 사분면 내에 존재한다면 해당 사분면을 4등분
  - 현재 사분면의 1/2/3/4 각각의 재귀함수 호출
  - 현재 사분면 내에 존재하지 않을 시 탐색할 필요 없으므로 크기를 2배
*/

#include<iostream>
#define endl '\n'
using namespace std;
int N, R, C, res = 0;
void find_z(int x, int y, int size) {
    if (x == C && y == R) {
        cout << res << endl;
        return;
    }
    // R, C가 현재 사분면에 존재 시
    if (C < x+size && C >= x && R < y+size && R >= y) {
        // 사분면 탐색
        find_z(x, y, size/2);
        find_z(x+size/2, y, size/2);
        find_z(x, y+size/2, size/2);
        find_z(x+size/2, y+size/2, size/2);
    } else {
        res += size*size;
// cout << "res: " << res << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> R >> C;
    find_z(0, 0, (1 << N));
    return 0;
}