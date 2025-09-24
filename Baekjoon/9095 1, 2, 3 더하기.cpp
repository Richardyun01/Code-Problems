/*
  �˰��� �з�: ���̳��� ���α׷���

  ���� ��� �� ����
  - ���� �߼�: 1�� �� 1, 2�� �� 2, 3�� �� 4, 4�� �� 7, ...
  - �̸� �ݺ��ϴ� ���� n��° ���� ����� ���� n-1, n-2, n-3��° ���� ��츦 ��ģ �Ͱ� ������ �߰� ����
  - ���� ��ȭ�� dp[n] = dp[n-1]+dp[n-2]+dp[n-3] ȹ��
  - ��ȭ�� ������ ��� ó���� �����ϹǷ� ���� ���� �����ϰ� ó���� �ʿ䰡 ����
*/

#include<iostream>
#include<vector>
using namespace std;
int T, dp[1001];
int main() {
    cin >> T;
    // ��ȭ�� ����
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    for (int i = 0; i < T; i++) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << endl;
    }
    return 0;
}