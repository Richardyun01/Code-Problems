/*
  �˰��� �з�: ���� ��

  ���� ��� �� ����
  - i�� j�� �Է¹��� �� for ������ ������ Ž���ؼ� ���� ���ϸ� �ð� �ʰ� �߻�
  - ���� ���� ���: ��Ŀ� ���ؼ� �� �ε��������� ������ ���� ���ϱ�
  - N���� ���� �����ϸ鼭 Ư�� �ε����� ���� ���� ���� �ε����� ���� �� - ���� �ε����� ��
  - Ư�� ������ ���� ���� �ִ밪 ���� �� - (�ּҰ�-1) ���� ��
*/

#include<iostream>
#define endl '\n'
using namespace std;
int N, M;
int n[100001], ps[100001] = {0,};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    // ������ ���
    for (int i = 1; i <= N; i++) {
        cin >> n[i];
        ps[i] = ps[i-1] + n[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b, sum = 0;
        cin >> a >> b;
        cout << (ps[b] - ps[a-1]) << endl;
    }
    return 0;
}