/*
  �˰��� �з�: ����, ���ڿ�, �ؽ�

  ���� ��� �� ����
  - ���ڿ��� ���ĺ��� ���� ���� ��ȯ, ������ ���� 31�� ���ϰ� ��� ���ϱ�� ���� �⺻���� ����
  - �������� m���� ������ ���ϱ�� 50�� ¥�� �߻�
  - �� �ܰ踶�� m���� �������� ���Ͽ� ũ�� ������ �ؾ� ��
  - r ���� �� �ܰ踶�� ������Ű�� m���� �������� ���ؾ� ��
*/

#include<iostream>
#define endl '\n'
using namespace std;
typedef long long ll;
int alphabet_to_num(char c) {
    return c - 96;
}
int m = 1234567891;
// 1���� �����Ͽ� 31�� ����
long long r = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L;
    string hash_string;
    cin >> L >> hash_string;
    ll H = 0;
    for (int i = 0; i < L; i++) {
        // m���� ������ ũ�� ������ �̸��̸� �ؾ� ��
        H += (ll)(alphabet_to_num(hash_string[i]) * r) % m;
        // r�� m���� ����� ũ�� ������ �ؾ� ��
        r = (r*31) % m; 
    }
    cout << H % m << endl;
    return 0;
}