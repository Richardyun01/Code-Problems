/*
  �˰��� �з�: ����, ������, ��Ŭ���� ȣ����

  ���� ��� �� ����
  - ��Ŭ���� ȣ����: �ִ������� ���ϴ� ���
    - �� �� a, b�� �־����� ��
    - b == 0�̶�� a�� �ִ������� �ǰ� �׷��� ������ b�� a%b�� �ִ������� Ž��
    - �̸� ��������� �ݺ�
  - �ּҰ������ �׳� �� ���� ���ϰ� �ִ������� ������ ��
*/

#include<iostream>
#define endl '\n'
using namespace std;
int find_gcd(int a, int b) {
    if (b == 0) return a;
    else return find_gcd(b, a%b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, gcd, lcm;
    cin >> n >> m;
    int r;
    gcd = find_gcd(n, m);
    lcm = n*m/gcd;
    cout << gcd << endl << lcm << endl;
    return 0;
}