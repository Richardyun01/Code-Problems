/*
  �˰��� �з�: ���� ����, ���

  - ���� ��� �� ����
  - ���� Ž���ϰ��� �ϴ� ��и��� ���� ���� �� ��ǥ�� �Է¹޴� �Լ� ����
  - ã���� �ϴ� ��ǥ���� ���� ��и� ���� �����Ѵٸ� �ش� ��и��� 4���
  - ���� ��и��� 1/2/3/4 ������ ����Լ� ȣ��
  - ���� ��и� ���� �������� ���� �� Ž���� �ʿ� �����Ƿ� ũ�⸦ 2��
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
    // R, C�� ���� ��и鿡 ���� ��
    if (C < x+size && C >= x && R < y+size && R >= y) {
        // ��и� Ž��
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