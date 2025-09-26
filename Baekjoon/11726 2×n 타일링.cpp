/*
  �˰��� �з�: ���̳��� ���α׷���

  ���� ��� �� ����
  - 2*1 ũ�� ���簢�� = 1����
  - 2*2 ũ�� ���簢�� = 2����
  - 2*3 ũ�� ���簢�� = 3����, 2*4 ũ�� ���簢�� = 5����, ...
  - ���� ������ ���� ��ȭ�� dp[i] = dp[i-1] + dp[i-2]�� �����س� �� ����
*/

#include<iostream>
#define endl '\n'
using namespace std;
int N, dp[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        // ��ȭ��
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] = dp[i] % 10007;
    }
    cout << dp[N] << endl;
    return 0;
}