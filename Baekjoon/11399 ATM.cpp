/*
  �˰��� �з�: �׸��� �˰���, ����

  ���� ��� �� ����
  - �ð��� ���� �ּ�ȭ�ϴ� ���: ���� ���� ���� ���� ���� ���ϰ� ���� ū ���� ���� ���� ���ϸ� ��
  - �̴� �迭�� �����ϰ� ������� ���ϴ� ������� ���� ����
  - ������������ ������ �� ���� �ε��� ��ȣ+1��ŭ ���ϰ� ���ϸ� ��
*/

#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
int N, sum = 0;
int P[1001];
// ������������ ����
bool compare(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    // ������������ ����
    sort(P, P+N, compare);
    // �ջ�
    for (int i = 0; i < N; i++) {
        sum += P[i] * (i+1);
    }
    cout << sum << endl;
    return 0;
}